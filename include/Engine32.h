#ifndef ENGINE_32
#define ENGINE_32

#include <memory>

class ScreenBuffer;
using screen_buffer_up = std::unique_ptr<ScreenBuffer>;

struct WebServerConfig;
class Connection;
using connection_up = std::unique_ptr<Connection>;

// struct HardwareConfig;
// class Controller;
// using controller_up = std::unique_ptr<Controller>;

class Engine32
{
private:
    screen_buffer_up    m_screen_buffer;
    connection_up       m_connection;
    // controller_up       m_controller;
public:
    Engine32(const WebServerConfig& web_server_config);
    ~Engine32();
private:
    void register_web_routes();
};

#endif