#ifndef HARDWARE_CONFIG
#define HARDWARE_CONFIG

#include <cstdint>

struct HardwareConfig
{
    /**
     * A Button pin
     * IO 00
     */
    const static inline std::uint8_t A_PIN = 0;
    
    /**
     * B Button pin
     * IO 00
     */
    const static inline std::uint8_t B_PIN = 0;

    /**
     * Joystic pinout
     */

    std::uint8_t a_pin{A_PIN};
    std::uint8_t b_pin{B_PIN};

};

#endif