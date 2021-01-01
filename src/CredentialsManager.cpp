#include "CredentialsManager.h"

CredentialsManager::CredentialsManager()
{}


bool CredentialsManager::addCredentials(std::unique_ptr<Credentials> credentials)
{
    if (isCredentialsRegistered(CharToString(credentials.get()->getDomain().first)))
    {
        CredentialsError("Credentials with domain name : \"" + CharToString(credentials->getDomain().first) + "\" already registered.").raise();
    }
    credentialsDomains_.emplace(CharToString(credentials->getDomain().first));
    //std::unique_ptr<Credentials> newCredentials = std::make_unique<Credentials>(credentials);
    //std::cout << "Add " << *newCredentials << std::endl;
    //credentials_.emplace(move(newCredentials));
    //credentials_.emplace(std::make_unique<Credentials>(credentials));
    credentials_.emplace(move(credentials));
    return true;
}

bool CredentialsManager::updateCredentials(Credentials& credentials)
{
    if (!isCredentialsRegistered(credentials))
    {
        CredentialsError("Credentials with domain name : \"" + CharToString(credentials.getDomain().first) + "\" not registered.").raise();
    }
    credentials_.emplace(std::make_unique<Credentials>(credentials));
    return true;
}

bool CredentialsManager::removeCredentials(Credentials& credentials)
{
    if (!isCredentialsRegistered(credentials))
    {
        CredentialsError("Credentials with domain name : \"" + CharToString(credentials.getDomain().first) + "\" not registered.").raise();
    }
    credentialsDomains_.erase(CharToString(credentials.getDomain().first));
    /// TODO
    /*auto& it = find_if(credentials_.begin(), credentials_.end(), [&credentials](std::unique_ptr<Credentials>& credentialsFromSet)
    {
        return CharToString(credentials.getDomain().first) == CharToString(credentialsFromSet.get()->getDomain().first);
    });*/
    //credentials_.erase(it);
    return true;
}

std::ostream& operator<<(std::ostream& out, const CredentialsManager& credentialsManager)
{
    out << credentialsManager.credentials_.size() << " credentials registered" << std::endl;
    out << credentialsManager.credentialsDomains_.size() << " domains registered" << std::endl;
    for(auto& it : credentialsManager.credentialsDomains_)
    {
        out << "   " << it << std::endl;
    }
    return out;
}

std::unordered_set<unique_ptr<Credentials>>& CredentialsManager::getCredentials()
{
    return credentials_;
}

bool CredentialsManager::isCredentialsRegistered(const Credentials& credentials)
{
    //return (credentialsDomains_.find(CharToString(credentials.getDomain().first)) != credentialsDomains_.end());
    return isCredentialsRegistered(CharToString(credentials.getDomain().first));
}

bool CredentialsManager::isCredentialsRegistered(const std::string& domain)
{
    return (credentialsDomains_.find(domain) != credentialsDomains_.end());
}