#include "Utility.h"

std::string CharToString(unsigned char* ptr)
{
    std::string cString;
    while(*ptr != '\0')
    {
        cString += *ptr++;
    }
    //cString += '\0';
    return cString;
}

std::string CharToString(unsigned char* ptr, unsigned int len)
{
    std::string cString;
    for(int i = 0; i < len; i++)
    {
        cString += *ptr++;
    }
    //cString += '\0';
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

/*std::istream& operator>>(std::istream& in, unsigned char* ptr)
{
     while(*ptr != '\0')
    {
        in >> *ptr++;
    }
    return in;
}*/