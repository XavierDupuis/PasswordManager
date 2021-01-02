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
    std::string rawCredentials;
    std::string domain;
    std::string password;

    unsigned value;
    
    //Get each line from .txt
    while(!ws(f).eof()) 
    {
        if(std::getline(f,rawCredentials))
        {
            std::istringstream line(rawCredentials);
            line >> std::quoted(domain);
            cout << domain << std::endl;
            while(line >> std::hex >> value)
            {
                unsigned char cValue = value;
                password += cValue;
                std::cout << std::dec << " " << cValue << " (dec " << unsigned(cValue) << " == hex " << std::hex << unsigned(cValue) <<  ")" <<  " added. Pass : " << password << std::endl;
            }
            line.ignore();
            credentialsManager.addCredentials(make_unique<Credentials>(make_pair(StringToChar(domain), domain.size()),
                                make_pair(StringToChar(password), password.size())));
            password.clear();
        }
        else
        {
            throw runtime_error("Error while parsing file");
        }
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