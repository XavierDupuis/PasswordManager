#include "Credentials.h"

Credentials::Credentials(std::pair<unsigned char*, unsigned> domain, std::pair<unsigned char*,unsigned> password, unsigned char* key) 
    : domain_(domain)
{
    //unsigned int* outLen = new unsigned int;
    password_.first = EncryptECB(password.first, password.second, key, password_.second); 
    //password_.second = *outLen;
    //delete outLen;
}

Credentials::Credentials(std::pair<unsigned char*, unsigned> domain, std::pair<unsigned char*, unsigned> password)
    : domain_(domain)
    , password_(password)
{}

unsigned char* Credentials::getDomain()
{
    return domain_.first;
}

unsigned char* Credentials::getEncryptedPassword()
{
    return password_.first;
}

unsigned char* Credentials::getDecryptedPassword(unsigned char* key)
{
    return DecryptECB(password_.first, password_.second, key); 
}
