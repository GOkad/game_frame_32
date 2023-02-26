#include <cstdint>
#include <string>

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"

#include "JSONBuilder.h"

#include "config/.WebServerConfig.h"
#include "m32.h"
#include "Engine32.h"

#include "config/HardwareConfig.h"
#include "Controller.h"

Engine32::Engine32(const WebServerConfig& web_server_config, const HardwareConfig& harware_config):
    m_server{std::make_unique<AsyncWebServer>(80)},
    m_controller{std::make_unique<Controller>(harware_config)}
{
    Serial.print("Engine running on Core: ");
    Serial.println(xPortGetCoreID());

    setup_access_point(web_server_config);
    register_routes();
    m_server->begin();
}

Engine32::~Engine32() = default;

void Engine32::connect_to_network(const WebServerConfig &config)
{
    WiFi.begin(config.network_ssid, config.network_password);

    unsigned long stamp = millis();
    while (
        WiFi.status() != WL_CONNECTED &&
        ( millis() - stamp) < config.NETWORK_CONNECTION_TIMEOUT
    )
    {
      delay(500);
      Serial.print(".");
    }

    if ( WiFi.status() != WL_CONNECTED ) {
        Serial.println("Failed to connect to network!");
        return;
    }

    Serial.println("");
    Serial.print("Connected to: ");
    Serial.println(config.network_ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void Engine32::setup_access_point(const WebServerConfig& config)
{
    WiFi.softAP(config.ssid, config.password);
    Serial.println(WiFi.softAPIP().toString());
}

void Engine32::register_routes()
{
    m_server->on("/", HTTP_GET,
    [](AsyncWebServerRequest* request){
        request->send(200, "text/html", m32);
    });

    m_server->on("/config", HTTP_GET,
    [](AsyncWebServerRequest* request){
        std::uint16_t width = request->hasParam("w") ?
            std::stoi(request->getParam("w")->value().c_str()) : 0;

        std::uint16_t height = request->hasParam("h") ?
            std::stoi(request->getParam("h")->value().c_str()) : 0;

        // cs = 50,
        // // Grid width [normalized for cursor x]
        // gw = m.floor(w/cs);
        // // Grid height [normalized for cursor y]
        // gh = m.floor(h/cs);
        // // Grid X offset
        // gxo = 0,
        // // Grid Y offset
        // gyo = 0,
        // // Cursor
        // // X postition
        // cx = 0,
        // // Y postition
        // cy = 0,
        // // Cursor size
        // crs = cs/2,
        // co = (cs-crs)/2
        JSONBuilder json;
        json.add_pair("s",123);
        json.add_pair("",123);
        request->send(200, "application/json", json.build().c_str());
    });

    m_server->on("/events", HTTP_GET,
    [](AsyncWebServerRequest* request){
        request->send(200, "application/json", "[]");
    });
}

void Engine32::event_loop()
{
    /**
     * Events
     * a:{
     * }
     * 
     */
    if (m_controller->a_pressed()) {Serial.println("A is pressed");}
    if (m_controller->b_pressed()) {Serial.println("B is pressed");}
    if (m_controller->c_pressed()) {Serial.println("C is pressed");}

    std::uint16_t x = m_controller->read_x();
    if (x <= 500) {Serial.print("right");}
    if (x >= 3500) {Serial.print("left");}

    std::uint16_t y = m_controller->read_y();
    if (y <= 500) {Serial.print("up");}
    if (y >= 3500) {Serial.print("down");}
    
    delay(1000);
}