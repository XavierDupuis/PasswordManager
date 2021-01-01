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
    out << "\"";
    unsigned char* ptr = credentials.domain_.first;
    for(unsigned i = 0; i < credentials.domain_.second; i++)
    {
        out << *ptr++;
    }
    out << "\" ";
    ptr = credentials.password_.first;
    for(unsigned j = 0; j < credentials.password_.second; j++)
    {
        out << std::setfill('0') << std::uppercase << std::setw(2) << std::hex << unsigned(*ptr++) << " ";
    }
    ptr = nullptr;
    out << std::endl;
    return out;
}

std::pair<unsigned char*, unsigned> Credentials::getDomain() const
{
    return domain_;
}

std::pair<unsigned char*, unsigned> Credentials::getEncryptedPassword() const
{
    return password_;
}

std::pair<unsigned char*, unsigned> Credentials::getDecryptedPassword(unsigned char* key)
{
    return make_pair(DecryptECB(password_.first, password_.second * sizeof(unsigned char), key), password_.second); 
}
