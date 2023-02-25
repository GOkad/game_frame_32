#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"

#include "config/.WebServerConfig.h"
#include "m32.h"
#include "Engine32.h"


Engine32::Engine32(const WebServerConfig& config):
    m_server{std::make_unique<AsyncWebServer>(80)}
{
    setup_access_point(config);
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

    m_server->on("/events", HTTP_GET,
    [](AsyncWebServerRequest* request){
        Serial.println("event loop");
        request->send(200, "application/json", "[]");
    });
}
