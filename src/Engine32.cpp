#include <Arduino.h>

#include "core/Connection.h"
#include "core/ScreenBuffer.h"
#include "Engine32.h"

Engine32::Engine32(const WebServerConfig& web_server_config):
    m_screen_buffer{std::make_unique<ScreenBuffer>()},
    m_connection{std::make_unique<Connection>(web_server_config)}
{
    
}
Engine32::~Engine32() = default;