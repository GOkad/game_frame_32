#ifndef JSON_BUILDER
#define JSON_BUILDER

#include <sstream>
#include <string>
#include <cstdint>

class JSONBuilder
{
private:
    std::stringstream m_stream;
    bool m_first = true;
public:
    JSONBuilder* add_pair(std::string key, std::uint8_t value)
    {
        m_stream << (m_first ? "" : ",") << "\"" << key << "\":\"" << (int)value <<"\"";
        return this;
    }

    std::string build()
    {
        return m_stream.str();
    }

};

#endif