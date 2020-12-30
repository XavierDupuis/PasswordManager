#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

std::string CharToString(unsigned char* ptr);

std::string CharToString(unsigned char* ptr, unsigned int len);

unsigned char* StringToChar(std::string str);

std::ostream& operator<<(std::ostream& out, unsigned char* ptr);

#endif //UTILITY_H