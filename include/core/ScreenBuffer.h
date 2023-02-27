#ifndef E32_SCREEN_BUFFER
#define E32_SCREEN_BUFFER

#include <vector>
#include <string>

using scr_buffer = std::vector<std::string>;
class ScreenBuffer
{
private:
    bool        m_can_read;
    scr_buffer  m_buffer;
public:
    ScreenBuffer()
    {
        m_can_read = true;
        m_buffer.clear();
    }
    const bool can_read() const
    {
        return m_can_read;
    }
    bool set_can_read(bool can_read)
    {
        m_can_read = can_read;
        return m_can_read;
    }
    std::string read()
    {
        // Return buffer
        return "\"r,10,10,50,50,0f0\"";
    }
};

#endif