#ifndef E32_COMPONENT
#define E32_COMPONENT

#include <cstdint>
#include <string>
#include <sstream>

enum ComponentTypes: char
{
    RECTANGLE = 'r'
};

struct Colors
{
    static inline const std::string BLACK   = "000";
    static inline const std::string RED     = "f00";
    static inline const std::string GREEN   = "0f0";
    static inline const std::string BLUE    = "00f";
};

class Component
{
private:
    ComponentTypes m_type;
    std::uint8_t m_x;
    std::uint8_t m_y;
    std::uint8_t m_width;
    std::uint8_t m_height;
    std::string m_color;
    char m_separator = ',';
public:
    Component(ComponentTypes type):
        m_type{type}
       {}

    void set_position(std::uint8_t x, std::uint8_t y)
    {
        m_x = x;
        m_y = y;

    }
    
    void set_size(std::uint8_t width, std::uint8_t height)
    {
        m_width = width;
        m_height = height;
    }

    void set_color(std::string color)
    {
        m_color = color;
    }

    std::string to_string()
    {
        std::stringstream component;

        // NOTE!
        // This will only work for Reactangle
        component <<
        m_type << m_separator <<
        (int)(m_x) << m_separator <<
        (int)(m_y) << m_separator <<
        (int)m_width << m_separator <<
        (int)m_height << m_separator <<
        m_color;

        return component.str();
    }

    ~Component() = default;
};

#endif
