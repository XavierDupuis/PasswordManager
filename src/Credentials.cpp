#include "Credentials.h"

Credentials::Credentials(std::pair<unsigned char*, unsigned> domain, std::pair<unsigned char*,unsigned> password, unsigned char* key) 
    : domain_(domain)
{
    //unsigned int* outLen = new unsigned int;
    password_.first = EncryptECB(password.first, password.second * sizeof(unsigned char), key, password_.second); 
    //password_.second = *outLen;
    //delete outLen;
}

Credentials::Credentials(std::pair<unsigned char*, unsigned> domain, std::pair<unsigned char*, unsigned> password)
    : domain_(domain)
    , password_(password)
{}

Credentials::~Credentials()
{
    for(unsigned i = 0; i < password_.second; i++)
    {
        *password_.first++ = '\0';
    }
    password_.first = nullptr;
    password_.second = 0;

    for(unsigned i = 0; i < domain_.second; i++)
    {
        *domain_.first++ = '\0';
    }
    domain_.first = nullptr;
    domain_.second = 0;
}

std::ostream& operator<<(std::ostream& out, const Credentials& credentials)
{
    out << "\"" << credentials.domain_.first << "\" " << credentials.password_.first << std::endl;
    return out;
}

std::pair<unsigned char*, unsigned> Credentials::getDomain()
{
    return domain_;
}

std::pair<unsigned char*, unsigned> Credentials::getEncryptedPassword()
{
    return password_;
}

std::pair<unsigned char*, unsigned> Credentials::getDecryptedPassword(unsigned char* key)
{
    return make_pair(DecryptECB(password_.first, password_.second * sizeof(unsigned char), key), password_.second); 
}
