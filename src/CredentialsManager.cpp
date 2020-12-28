#include "CredentialsManager.h"

bool CredentialsManager::addCredentials(Credentials& credentials)
{
    auto [it, result] = credentials_.emplace(std::make_unique<Credentials>(credentials));
    if (!result)
    {
        CredentialsError("Credentials with domain name : ")
    }
}

bool CredentialsManager::updateCredentials(Credentials& credentials)
{
    return true;
}

bool CredentialsManager::removeCredentials(unsigned char domain)
{
    return true;
}
