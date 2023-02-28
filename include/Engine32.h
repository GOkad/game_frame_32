#ifndef ENGINE_32
#define ENGINE_32

#include <memory>

class Screen;
using screen_up = std::unique_ptr<Screen>;

struct WebServerConfig;
class Connection;
using connection_up = std::unique_ptr<Connection>;

// struct HardwareConfig;
// class Controller;
// using controller_up = std::unique_ptr<Controller>;

typedef void(*callback_function)(void);

class Engine32
{
private:
    screen_up           m_screen;
    connection_up       m_connection;
    // controller_up       m_controller;
    callback_function   m_frame_cb;
public:
    Engine32(const WebServerConfig& web_server_config);
    ~Engine32();
    void set_frame_cb(callback_function frame_cb);
private:
    void register_web_routes();
};

#endif