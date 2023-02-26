#ifndef E32_CONNECTION
#define E32_CONNECTION

#include <memory>
#include <string>

#include <WiFi.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"
#include "config/.WebServerConfig.h"

#include "core/m32.h"

using async_web_server_up = std::unique_ptr<AsyncWebServer>;

class Connection
{
private:
    async_web_server_up m_server;
public:
    Connection(const WebServerConfig& config):
        m_server{std::make_unique<AsyncWebServer>(80)}
    {
        connect_to_network(config);
        setup_access_point(config);

        register_routes();
        m_server->begin();
    }


private:
    void connect_to_network(const WebServerConfig& config)
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
    void setup_access_point(const WebServerConfig& config)
    {
        WiFi.softAP(config.ssid, config.password);
        Serial.println(WiFi.softAPIP().toString());
    }
    void register_routes()
    {
        /**
         * Return HTML page with
         * JavaScript m32 engine
         * 
         */
        m_server->on("/", HTTP_GET,
        [](AsyncWebServerRequest* request){
            request->send(200, "text/html", m32);
        });

        /**
         * Get screen configuration
         * 
         * @param w - Screen Width
         * @param h - Screen Height
         */
        m_server->on("/cfg", HTTP_GET,
        [](AsyncWebServerRequest* request){
            std::string josn_config = "{}";
            request->send(200, "text/html", josn_config.c_str());
        });

        /**
         * Read the screen buffer
         */
        m_server->on("/sbuf", HTTP_GET,
        [](AsyncWebServerRequest* request){
            std::string json_sbuf = "[]";
            request->send(200, "text/html", json_sbuf.c_str());
        });

    }
};

#endif