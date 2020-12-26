#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "ExceptBadFileAccess.h"

class FileHandler 
{
public:
    FileHandler(std::string filename);
    bool readFile();
    bool writeFile();

private:
    std::string filename_;
};

#endif //FILEHANDLER_H