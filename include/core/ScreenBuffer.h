#ifndef E32_SCREEN_BUFFER
#define E32_SCREEN_BUFFER

#include <vector>
#include <string>
#include <sstream>

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
        std::stringstream stream;

        for( std::string element : m_buffer)
        {
            // Add " for JSON
            // TODO: Fix this
            stream << "\"" << element << "\",";
        }

        std::string stream_string = stream.str();
        std::string buffer_string = stream_string.substr(0, stream_string.size()-1);

        return buffer_string; 
    }

    /**
     * DEVELOPMENT METHOD ONLY
     * TO BE Extracted into examples
     */
    void demo(uint16_t screen_width, uint16_t screen_height)
    {
        Serial.print("Width: ");
        Serial.print(screen_width);
        Serial.print(" / Height: ");
        Serial.println(screen_height);

        m_can_read = false;
        
        const std::uint8_t cell_size = 50;
        const float grid_width = std::floor(screen_width/cell_size);
        const float grid_height = std::floor(screen_height/cell_size);

        // Rectangle element
        for(int y = 0; y < grid_height; y++ )
        {
            bool flag = ( y%2 == 0 );
            for(int x = 0; x < grid_width; x++ )
            {
                flag = !flag;
                std::stringstream cell;
                cell << "r" << "," <<
                        (int)(x*cell_size) << "," <<
                        (int)(y*cell_size) << "," <<
                        (int)cell_size << "," <<
                        (int)cell_size << "," <<
                        (flag ? "0f0" : "f00");
                m_buffer.push_back(cell.str());
            }
        }
        m_can_read = true;        
    }
};

#endif