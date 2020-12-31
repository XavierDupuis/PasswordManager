#include "FileHandler.h"

FileHandler::FileHandler(std::string filename = "data.txt") 
    : filename_(filename) 
{
}

bool FileHandler::readFile(CredentialsManager& credentialsManager)
{
    // Open file
    std::ifstream f(filename_);
    if(!f)
    {
        BadFileAccess("File " + filename_ + " not found").raise();
    }

    //Local Variables
    std::string ligne;
    std::string domain;
    unsigned char value;
    std::string password;

    //Get each line from .txt
    while(std::getline(f,ligne)) 
    {
        std::istringstream stream(ligne);
        stream >> std::quoted(domain);
        while(stream >> value)
        {
            password += value;
        }
        stream.ignore();
        Credentials cred = {make_pair(StringToChar(domain), domain.size()),
                            make_pair(StringToChar(password), password.size())};
        credentialsManager.addCredentials(cred);
    }
    f.close();
    return true;
}

bool FileHandler::writeFile(CredentialsManager& credentialsManager)
{
    std::ofstream f(filename_);
    if(!f)
    {
        BadFileAccess("File " + filename_ + " couldn't be overwritten.").raise();
    }
    for(auto& it : credentialsManager.getCredentials())
    {
        f << *it;
    }
    f.close();
    return true;
}