#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

std::string CharToString(unsigned char* ptr);

/*template <typename T>
T StringToChar(std::string str);*/

std::ostream& operator<<(std::ostream& out, unsigned char* ptr);

//std::istream& operator>>(std::istream& in, unsigned char* ptr);

#endif //UTILITY_H