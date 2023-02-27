#include <Arduino.h>

#include "core/Connection.h"
#include "core/ScreenBuffer.h"
#include "Engine32.h"

Engine32::Engine32(const WebServerConfig& web_server_config):
    m_screen_buffer{std::make_unique<ScreenBuffer>()},
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
     * Get screen configuration
     * 
     * @param w - Screen Width
     * @param h - Screen Height
     */
    m_connection->register_route("/cfg", WebRequestMethod::HTTP_GET,
    [](AsyncWebServerRequest* request){
        std::uint16_t width = request->hasParam("w") ?
            std::stoi(request->getParam("w")->value().c_str()) : 0;

        std::uint16_t height = request->hasParam("h") ?
            std::stoi(request->getParam("h")->value().c_str()) : 0;

        Serial.print("Width: ");
        Serial.println(width);

        Serial.print("Height: ");
        Serial.println(height);

        
        std::string josn_config = "{}";
        request->send(200, "text/html", josn_config.c_str());
    });

    /**
     * Read screen buffer
     */
    m_connection->register_route("/sbuf", WebRequestMethod::HTTP_GET,
    [screen_buffer = m_screen_buffer.get()](AsyncWebServerRequest *request){
        std::string response = "[";
        Serial.println("Waiting for ScreenBuffer...");
        while(!screen_buffer->can_read()) {
            Serial.print(".");
        }
        Serial.println("done");
        response += screen_buffer->read().c_str();
        response += "]";

        request->send(200, "text/html", response.c_str());
    });
}