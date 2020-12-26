#ifndef CREDENTIALSMANAGER_H
#define CREDENTIALSMANAGER_H

#include <iostream>
#include <vector>
#include <unordered_map>

class CredentialsManager 
{
public:
    CredentialsManager();

private:
    std::unordered_map<std::string,std::vector<unsigned char>> credentials_;
};

#endif //CREDENTIALSMANAGER_H