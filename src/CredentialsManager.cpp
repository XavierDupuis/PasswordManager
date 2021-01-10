#include "CredentialsManager.h"

CredentialsManager::CredentialsManager()
{}

void CredentialsManager::revealCredentials(std::string domain, std::string key)
{
    Credentials* foundCredentials = findCredentials(domain);
    std::pair<unsigned char *, unsigned int>* decryptedPassword = new std::pair<unsigned char *, unsigned int>;
    *decryptedPassword = foundCredentials->getDecryptedPassword(StringToChar(key));
    std::cout << domain << " : " << decryptedPassword->first << std::endl;
    delete decryptedPassword;
}

bool CredentialsManager::addCredentials(std::unique_ptr<Credentials> credentials)
{
    std::string domain = CharToString(credentials->getDomain());
    if (isCredentialsRegistered(domain))
    {
        CredentialsError("ERROR : Credentials with domain name \"" + domain + "\" already registered.").raise();
    }
    credentialsDomains_.emplace(domain);
    credentials_.push_back(move(credentials));
    std::cout << "Credentials with domain name \"" + domain + "\" added." << std::endl;
    return true;
}

bool CredentialsManager::updateCredentials(std::unique_ptr<Credentials> credentials)
{
    std::string domain = CharToString(credentials->getDomain());
    if (!isCredentialsRegistered(domain))
    {
        CredentialsError("ERROR : Credentials with domain name \"" + domain + "\" not registered.").raise();
    }
    if (!removeCredentials(domain))
    {
        return false;
    }
    credentialsDomains_.emplace(domain);
    credentials_.push_back(move(credentials));
    std::cout << "Credentials with domain name \"" + domain + "\" updated." << std::endl;
    return true;
}

bool CredentialsManager::removeCredentials(std::string domain)
{
    if (!isCredentialsRegistered(domain))
    {
        CredentialsError("ERROR : Credentials with domain name \"" + domain + "\" not registered.").raise();
    }
    credentialsDomains_.erase(domain);

    auto it = remove_if(credentials_.begin(), credentials_.end(), [&domain](std::unique_ptr<Credentials>& credentialsFromSet)
    {
        return domain == CharToString(credentialsFromSet.get()->getDomain());
    });

    for(auto i = credentials_.end(); i != it; i--)
    {
        std::cout << "Credentials with domain name \"" + CharToString(credentials_.back()->getDomain()) + "\" removed." << std::endl;
        credentials_.pop_back();
    }
    return true;
}

Credentials* CredentialsManager::findCredentials(const std::string& domain)
{
    auto it = find_if(credentials_.begin(), credentials_.end(), [&domain](std::unique_ptr<Credentials>& registeredCredentials)
    {
        return (domain == CharToString(registeredCredentials.get()->getDomain()));
    });
    if (it == credentials_.end())
    {
        CredentialsError("ERROR : Credentials with domain name \"" + domain + "\" not registered.").raise();
    }
    return it->get();
}

std::ostream& operator<<(std::ostream& out, const CredentialsManager& credentialsManager)
{
    if(credentialsManager.credentials_.size() == 0) 
    {
        out << "No credentials registered";
        return out;
    }
    out << credentialsManager.credentials_.size() << " credential(s) registered" << std::endl;
    out << credentialsManager.credentialsDomains_.size() << " domain(s) registered :" << std::endl;
    for(auto& it : credentialsManager.credentialsDomains_)
    {
        out << "  " << it << std::endl;
    }
    return out;
}

std::vector<unique_ptr<Credentials>>& CredentialsManager::getCredentials()
{
    return credentials_;
}

bool CredentialsManager::isCredentialsRegistered(const Credentials& credentials) const
{
    return isCredentialsRegistered(CharToString(credentials.getDomain()));
}

bool CredentialsManager::isCredentialsRegistered(const std::string& domain) const
{
    return (credentialsDomains_.find(domain) != credentialsDomains_.end());
}