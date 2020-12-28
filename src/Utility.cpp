#include "Utility.h"

std::string CharToString(unsigned char* ptr)
{
    std::string cString;
    while(*ptr != '\0')
    {
        cString += *ptr++;
    }
    cString += '\0';
    return cString;
}

/*unsigned char* StringToChar(std::string str)
{
    memcpy()
    return str.c_str();
}*/

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