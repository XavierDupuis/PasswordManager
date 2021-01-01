#ifndef CREDENTIALSMANAGER_H
#define CREDENTIALSMANAGER_H

#include <unordered_set>
#include <algorithm>
#include <memory>
#include <string>

#include "Credentials.h"
#include "Utility.h"
#include "ExceptCredentialsError.h"

class CredentialsManager 
{
public:
    CredentialsManager();

    bool addCredentials(std::unique_ptr<Credentials> credentials);
    bool updateCredentials(Credentials& credentials);
    bool removeCredentials(Credentials& credentials);

    //bool findCredentials(std::string domain);

    friend std::ostream& operator<<(std::ostream& out, const CredentialsManager& credentialsManager);

    std::unordered_set<unique_ptr<Credentials>>& getCredentials();

private:
    bool isCredentialsRegistered(const Credentials& credentials);
    bool isCredentialsRegistered(const std::string& domain);
    
    std::unordered_set<unique_ptr<Credentials>> credentials_;
    std::unordered_set<std::string> credentialsDomains_;
};

#endif //CREDENTIALSMANAGER_H