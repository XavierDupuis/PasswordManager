#ifndef INVALIDINPUT_H
#define INVALIDINPUT_H

#include <stdexcept>

class InvalidInput : public std::invalid_argument 
{
public:
    InvalidInput(std::string what_arg = "")
    : std::invalid_argument(what_arg) {} 

    virtual InvalidInput& raise() { throw *this; }
};

#endif // INVALIDINPUT_H
