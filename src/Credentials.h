#ifndef CREDENTIALS_H
#define CREDENTIALS_H

#include "AES.h"
#include <vector>

class Credentials : public AES
{
public:
    // New credentials constructor
    Credentials(std::pair<unsigned char*, unsigned> domain, std::pair<unsigned char*, unsigned> password, unsigned char* key);
    
    // Preexisting credentials constructor
    Credentials(std::pair<unsigned char*, unsigned> domain, std::pair<unsigned char*, unsigned> password);

    ~Credentials();

    friend std::ostream& operator<<(std::ostream& out, const Credentials& credentials);

    std::pair<unsigned char*, unsigned> getDomain();
    std::pair<unsigned char*, unsigned> getEncryptedPassword();
    std::pair<unsigned char*, unsigned> getDecryptedPassword(unsigned char* key);

private:
    std::pair<unsigned char*, unsigned> domain_;
    std::pair<unsigned char*, unsigned> password_;
};

#endif //CREDENTIALS_H