#include "Utility.h"

std::string CharToString(unsigned char* ptr, unsigned int len)
{
    std::string cString;
    for(int i = 0; i < len; i++)
    {
        cString += *ptr++;
    }
    return cString;
}

std::string CharToString(std::pair<unsigned char *, unsigned int> pair)
{
    std::string cString;
    for(int i = 0; i < pair.second; i++)
    {
        cString += *pair.first++;
    }
    return cString;
}

unsigned char* StringToChar(std::string str)
{
    size_t a = str.size();
    unsigned char* out = new unsigned char[str.size()];
    for(unsigned i = 0; i < str.size(); i++)
    {
        out[i] = str[i];
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, unsigned char* ptr)
{   
    while(*ptr != '\0')
    {
        out << *ptr++;
    }
    return out;
}