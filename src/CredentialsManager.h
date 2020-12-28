#ifndef CREDENTIALSMANAGER_H
#define CREDENTIALSMANAGER_H

#include <vector>
#include <unordered_set>
#include <memory>
#include <string>

#include "Credentials.h"
#include "ExceptCredentialsError.h"

class CredentialsManager 
{
public:
    CredentialsManager();

    bool addCredentials(Credentials& credentials);
    bool updateCredentials(Credentials& credentials);
    bool removeCredentials(unsigned char domain);

private:
    std::unordered_set<std::unique_ptr<Credentials>> credentials_;
};

#endif //CREDENTIALSMANAGER_H