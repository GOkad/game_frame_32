#ifndef E32_SCREEN
#define E32_SCREEN

#include <vector>
#include <string>
#include <sstream>

class Screen
{
private:
    bool m_can_read;
    std::vector<std::string>  m_buffer;
public:
    Screen()
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
    void write_to_buffer(std::string component)
    {
        m_buffer.push_back(component);
    }
    std::string read_buffer()
    {
        std::stringstream stream;

        stream << "[";

        for( std::string element : m_buffer)
        {
            stream << "\"" << element << "\",";
        }

        std::string stream_string = stream.str();
        std::string buffer_string = stream_string.substr(0, stream_string.size()-1);

        buffer_string += "]";
        
        return buffer_string; 
    }
};

#endif