#ifndef HARDWARE_CONFIG
#define HARDWARE_CONFIG

#include <cstdint>

/**
 * Usable IO pins
 * 16, 17, 18, 19, 34, 35, 33, 5, 2
 * 
 * 32, 33, 34, 35
 */

struct HardwareConfig
{
    /**
     * A Button pin (16)
     */
    const static inline std::uint8_t A_PIN = 16;
    
    /**
     * B Button pin (17)
     */
    const static inline std::uint8_t B_PIN = 17;


    /**
     * C Button pin (5)
     */
    const static inline std::uint8_t C_PIN = 5;

    /**
     * Joystic X position pin (32)
     */
    const static inline std::uint8_t X_PIN = 32;

    /**
     * Joystic Y  position pin (33)
     */
    const static inline std::uint8_t Y_PIN = 33;

    std::uint8_t a_pin{A_PIN};
    std::uint8_t b_pin{B_PIN};
    std::uint8_t c_pin{C_PIN};
    std::uint8_t x_pin{X_PIN};
    std::uint8_t y_pin{Y_PIN};

};

#endif