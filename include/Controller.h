#ifndef CONTROLLER
#define CONTROLLER

#include <cstdint>

struct HardwareConfig;

class Controller
{
private:
    std::uint8_t m_a_pin;
    std::uint8_t m_b_pin;
    std::uint8_t m_c_pin;
    std::uint8_t m_x_pin;
    std::uint8_t m_y_pin;
public:
    Controller(const HardwareConfig& config);
    bool a_pressed();
    bool b_pressed();
    bool c_pressed();
    std::uint16_t read_x();
    std::uint16_t read_y();
};

#endif