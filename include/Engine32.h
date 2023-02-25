#ifndef ENGINE_32
#define ENGINE_32
#include "config/.WebServerConfig.h"
#include <memory>

class AsyncWebServer;
using async_web_server_up = std::unique_ptr<AsyncWebServer>;

struct WebServerConfig;

class Engine32
{
private:
    async_web_server_up m_server;
public:
    Engine32(const WebServerConfig& config);
    ~Engine32();
private:
    void connect_to_network(const WebServerConfig &config);
    void setup_access_point(const WebServerConfig& config);
    void register_routes();
};

#endif
