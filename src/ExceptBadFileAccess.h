#ifndef BADFILEACCESS_H
#define BADFILEACCESS_H

#include <stdexcept>

class BadFileAccess : public std::runtime_error
{
public:
    BadFileAccess(std::string what_arg = "")
    : std::runtime_error(what_arg) {} 

    virtual BadFileAccess& raise() { throw *this; }
};

#endif // BADFILEACCESS_H
