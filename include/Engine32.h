#ifndef ENGINE_32
#define ENGINE_32

#include <memory>
#include <unordered_map>

#include "config/CallbackEvents.h"

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
    std::unordered_map<CallbackEvents,callback_function> m_events;
public:
    Engine32(const WebServerConfig& web_server_config);
    ~Engine32();
    void register_event(CallbackEvents event, callback_function frame_cb);
    void trigger(CallbackEvents event);
    void engine_test()
    {
        Serial.println("test");
    }
private:
    void register_web_routes();
};

#endif