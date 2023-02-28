#include <Arduino.h>

#include "core/Connection.h"
#include "core/Screen.h"
#include "Engine32.h"

Engine32::Engine32(const WebServerConfig& web_server_config):
    m_screen{std::make_unique<Screen>()},
    m_connection{std::make_unique<Connection>(web_server_config)}
{
    register_web_routes();
}
Engine32::~Engine32() = default;

void Engine32::register_web_routes()
{

    /**
     * Get index page
     */
    m_connection->register_route("/", WebRequestMethod::HTTP_GET,
    [](AsyncWebServerRequest* request){
        request->send(200, "text/html", m32);
    });

    /**
     * Get game config
     * 
     * @param w - Screen Width
     * @param h - Screen Height
     */
    m_connection->register_route("/cfg", WebRequestMethod::HTTP_GET,
    [
        screen = m_screen.get()
    ](AsyncWebServerRequest* request){
        std::uint16_t screen_width = request->hasParam("w") ?
            std::stoi(request->getParam("w")->value().c_str()) : 0;

        std::uint16_t screen_height = request->hasParam("h") ?
            std::stoi(request->getParam("h")->value().c_str()) : 0;


        std::string josn_config = "{}";
        request->send(200, "text/html", josn_config.c_str());
    });

    /**
     * Read screen buffer
     */
    m_connection->register_route("/sbuf", WebRequestMethod::HTTP_GET,
    [
        frame_cb = m_frame_cb,
        screen = m_screen.get()
    ](AsyncWebServerRequest *request){
        
        frame_cb();
        std::string response = "[";
        // Serial.println("Waiting for ScreenBuffer...");
        while(!screen->can_read()) {
            // Serial.print(".");
        }
        // Serial.println("done");
        response += screen->read_buffer().c_str();
        response += "]";
        Serial.println(response.c_str());

        request->send(200, "text/html", response.c_str());
    });
}

/**
 * Set all re-calculations for the frame
 * 
 */
void Engine32::set_frame_cb(callback_function frame_cb)
{
    m_frame_cb = frame_cb;
}