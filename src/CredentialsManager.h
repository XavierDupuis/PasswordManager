#ifndef CREDENTIALSMANAGER_H
#define CREDENTIALSMANAGER_H

#include <vector>
#include <unordered_set>
#include <memory>
#include <string>

#include "Credentials.h"
#include "Utility.h"
#include "ExceptCredentialsError.h"

class CredentialsManager 
{
public:
    CredentialsManager();

    bool addCredentials(Credentials& credentials);
    bool updateCredentials(Credentials& credentials);
    bool removeCredentials(Credentials& credentials);

    std::unordered_set<std::unique_ptr<Credentials>>& getCredentials();

private:
    bool findCredentials(Credentials& credentials);
    
    std::unordered_set<std::unique_ptr<Credentials>> credentials_;
    std::unordered_set<std::string> credentialsDomains_;
};

#endif //CREDENTIALSMANAGER_H