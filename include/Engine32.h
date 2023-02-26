#ifndef ENGINE_32
#define ENGINE_32

#include <memory>

struct WebServerConfig;
class Connection;
using connection_up = std::unique_ptr<Connection>;

// struct HardwareConfig;
// class Controller;
// using controller_up = std::unique_ptr<Controller>;

class Engine32
{
private:
    connection_up   m_connection;
    // controller_up       m_controller;
public:
    Engine32(const WebServerConfig& web_server_config);
    ~Engine32();
private:
};

#endif