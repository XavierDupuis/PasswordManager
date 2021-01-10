#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "CredentialsManager.h"
#include "ExceptBadFileAccess.h"

class FileHandler 
{
public:
    FileHandler();
    FileHandler(std::string filename);
    bool readFile(CredentialsManager& credentialsManager);
    bool writeFile(CredentialsManager& credentialsManager);

private:
    std::string filename_;
};

#endif //FILEHANDLER_H