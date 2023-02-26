#include <Arduino.h>

#include "config/HardwareConfig.h"
#include "Controller.h"

Controller::Controller(const HardwareConfig& config):
    m_a_pin{config.a_pin},
    m_b_pin{config.b_pin},
    m_c_pin{config.c_pin},
    m_x_pin{config.x_pin},
    m_y_pin{config.y_pin}
{
    pinMode(m_a_pin, INPUT);
    pinMode(m_b_pin, INPUT);
    pinMode(m_c_pin, INPUT);
    pinMode(m_x_pin, INPUT);
    pinMode(m_y_pin, INPUT);
}

bool Controller::a_pressed()
{
    return digitalRead(m_a_pin) == 1;
}
bool Controller::b_pressed()
{
    return digitalRead(m_b_pin) == 1;
}
bool Controller::c_pressed()
{
    return digitalRead(m_c_pin) == 1;
}
std::uint16_t Controller::read_x()
{
    return analogRead(m_x_pin);
}
std::uint16_t Controller::read_y()
{
    return analogRead(m_y_pin);
}