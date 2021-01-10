#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "CredentialsManager.h"
#include "FileHandler.h"
#include "ExceptBadFileAccess.h"
#include "ExceptCredentialsError.h"
#include "ExceptInvalidInput.h"
#include <iomanip>
#include <vector>

class Controller 
{
public:
    Controller(CredentialsManager& credentialsManager);

    void routine();
    bool menu();

private:

    void revealCredentials();

    std::unique_ptr<Credentials> inputCredentials();

    template<typename T>
    T input(std::string query);

    std::pair<unsigned, std::string> options_ = {   
                                                    6, "0 - Exit \n" 
                                                    "1 - Reveal Credentials \n"
                                                    "2 - Add    Credentials \n"
                                                    "3 - Update Credentials \n"
                                                    "4 - Remove Credentials \n" 
                                                    "5 - Display registered domains \n"
                                                };

    CredentialsManager& credentialsManager_;
};

#endif //CONTROLLER_H

