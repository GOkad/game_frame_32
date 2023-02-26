#include <Arduino.h>

#include "core/Connection.h"
#include "Engine32.h"

Engine32::Engine32(const WebServerConfig& web_server_config):
    m_connection{std::make_unique<Connection>(web_server_config)}
{
}
Engine32::~Engine32() = default;