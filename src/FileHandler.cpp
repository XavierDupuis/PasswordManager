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
    std::string password;

    unsigned char value1, value2;
    
    //Get each line from .txt
    while(std::getline(f,ligne)) 
    {
        std::istringstream stream(ligne);
        stream >> std::quoted(domain);
        while(stream >> std::hex >> value1 >> value2)
        {
            //unsigned char cValue = static_cast<unsigned char>(value);
            unsigned char cValue = value1 * 16 + value2;
            password += cValue;
            //std::cout << cValue << "(dec " << unsigned(cValue) << " == hex " << std::hex << unsigned(cValue) <<  ")" <<  " added. Pass : " << password << std::endl;
        }
        stream.ignore();
        //std::unique_ptr<Credentials> cred = make_unique<Credentials>({make_pair(StringToChar(domain), domain.size()),
        //                    make_pair(StringToChar(password), password.size())});
        //credentialsManager.addCredentials(cred);
        credentialsManager.addCredentials(make_unique<Credentials>(make_pair(StringToChar(domain), domain.size()),
                            make_pair(StringToChar(password), password.size())));
        password.clear();
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