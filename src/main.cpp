#include "Controller.h"
#include "CredentialsManager.h"
#include "FileHandler.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int main() 
{
    // - - - BEGIN PROGRAM MAIN - - - 
    CredentialsManager credentialsManager;
    Controller controller(credentialsManager);
    controller.routine();
    // - - - END PROGRAM MAIN - - - 
    return 0;
}