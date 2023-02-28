#ifndef E32_CONNECTION
#define E32_CONNECTION

#include <memory>
#include <cstdint>
#include <string>

#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include "ESPAsyncWebServer.h"
#include "config/.WebServerConfig.h"

#include "core/m32.h"

using async_web_server_up   = std::unique_ptr<AsyncWebServer>;

class Connection
{
private:
    async_web_server_up m_server;
public:
    Connection(const WebServerConfig& config, bool add_network_connection = false):
        m_server{std::make_unique<AsyncWebServer>(80)}
    {
        if(add_network_connection)
        {
            connect_to_network(config);
        }
        setup_access_point(config);

        m_server->begin();
    }
    void register_route(const char* uri, WebRequestMethod method, ArRequestHandlerFunction callback)
    {
        m_server->on(uri, method, callback);
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
};

#endif