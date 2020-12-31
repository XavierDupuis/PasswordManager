#include "CredentialsManager.h"

CredentialsManager::CredentialsManager()
{}

bool CredentialsManager::findCredentials(Credentials& credentials)
{
    return (credentialsDomains_.find(CharToString(credentials.getDomain().first)) != credentialsDomains_.end());
}

bool CredentialsManager::addCredentials(Credentials& credentials)
{
    if (findCredentials(credentials))
    {
        CredentialsError("Credentials with domain name : \"" + CharToString(credentials.getDomain().first) + "\" already registered.").raise();
    }
    credentialsDomains_.emplace(CharToString(credentials.getDomain().first));
    credentials_.emplace(std::make_unique<Credentials>(credentials));
    return true;
}

bool CredentialsManager::updateCredentials(Credentials& credentials)
{
    if (!findCredentials(credentials))
    {
        CredentialsError("Credentials with domain name : \"" + CharToString(credentials.getDomain().first) + "\" not registered.").raise();
    }
    credentials_.emplace(std::make_unique<Credentials>(credentials));
    return true;
}

bool CredentialsManager::removeCredentials(Credentials& credentials)
{
    if (!findCredentials(credentials))
    {
        CredentialsError("Credentials with domain name : \"" + CharToString(credentials.getDomain().first) + "\" not registered.").raise();
    }
    credentialsDomains_.erase(CharToString(credentials.getDomain().first));
    /*credentials_.erase(find(credentials_.begin(), credentials_.end(), [&credentials](const std::unique_ptr<Credentials>& credentialsFromSet)
    {
        return CharToString(credentials.getDomain().first) ==  CharToString(credentialsFromSet.get()->getDomain().first);
    }));*/
    return true;
}

std::ostream& operator<<(std::ostream& out, const CredentialsManager& credentialsManager)
{
    out << credentialsManager.credentialsDomains_.size() << " credentials registered" << std::endl;
    for(auto it : credentialsManager.credentialsDomains_)
    {
        out << "   " << it << std::endl;
    }
    return out;
}

std::unordered_set<std::unique_ptr<Credentials>>& CredentialsManager::getCredentials()
{
    return credentials_;
}