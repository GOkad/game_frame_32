#ifndef ENGINE_32
#define ENGINE_32
#include "config/.WebServerConfig.h"
#include <memory>

struct WebServerConfig;
class AsyncWebServer;
using async_web_server_up = std::unique_ptr<AsyncWebServer>;

struct HardwareConfig;
class Controller;
using controller_up = std::unique_ptr<Controller>;

class Engine32
{
private:
    async_web_server_up m_server;
    controller_up       m_controller;
public:
    Engine32(const WebServerConfig& web_server_config, const HardwareConfig& harware_config);
    ~Engine32();
    void static connect_to_network(const WebServerConfig &config);
    void event_loop();
private:
    void setup_access_point(const WebServerConfig& config);
    void register_routes();
};

#endif
