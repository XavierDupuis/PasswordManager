#ifndef CREDENTIALSERROR_H
#define CREDENTIALSERROR_H

#include <stdexcept>

class CredentialsError : public std::logic_error 
{
public:
    CredentialsError(std::string what_arg = "")
    : std::logic_error(what_arg) {} 

    virtual CredentialsError& raise() { throw *this; }
};

#endif // CREDENTIALSERROR_H
