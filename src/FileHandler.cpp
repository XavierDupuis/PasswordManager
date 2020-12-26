#include "FileHandler.h"

FileHandler::FileHandler(std::string filename = "data.txt") 
    : filename_(filename) 
{
}

bool FileHandler::readFile()
{
    // Open file
    std::ifstream f(filename_);
    if(!f)
    {
        BadFileAccess("File " + filename_ + " not found").raise();
    }

    //Local Variables
    std::string domain;
    std::string ligne;

    //Get each line from .txt
    while(std::getline(f,ligne)) 
    {
        std::istringstream stream(ligne);
        getline(stream, domain, ' ');
        stream >> domain;
        stream.ignore();
        //taskManager.addTask(std::make_unique<Task>(name, weight, value));
    }
    f.close();
    return true;
}

bool FileHandler::writeFile()
{
    std::ofstream f(filename_);
    if(!f)
    {
        BadFileAccess("File " + filename_ + " couldn't be overwritten.").raise();
    }
    /*for(auto& it : taskManager.getTasks())
    {
        f << it.get()->name_     << ";" << 
             it.get()->weight_   << ";" << 
             it.get()->value_    << std::endl;
    }*/
    f.close();
    return true;
}