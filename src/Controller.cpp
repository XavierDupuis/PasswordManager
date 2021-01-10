#include "Controller.h"

Controller::Controller(CredentialsManager& credentialsManager) 
    : credentialsManager_(credentialsManager)
{
}

void Controller::routine()
{
    FileHandler fileHandler = FileHandler();

    try
    {
        fileHandler.readFile(credentialsManager_);
        std::cout << credentialsManager_;
    } 
    catch (BadFileAccess& except)
    {
        std::cout << except.what() << std::endl;
        std::cout << "'data.txt' will be created" << std::endl;
        std::cout << "Close and restart program" << std::endl;
        fileHandler.writeFile(credentialsManager_);
        return;
    }

    bool exit = false;
    while (!exit)
    {
        try 
        {
            exit = menu();
        } 
        catch (InvalidInput& except)
        {
            std::cout << except.what() << std::endl;
        }
        catch (CredentialsError& except)
        {
            std::cout << except.what() << std::endl;
        }
        catch (BadFileAccess& except)
        {
            std::cout << except.what() << std::endl;
            exit = true;
        }
    }
    cout << " END " << credentialsManager_;
    fileHandler.writeFile(credentialsManager_);
}

bool Controller::menu()
{
    std::cout << std::endl << std::endl << options_.second << std::endl;
    unsigned option = input<unsigned>("Option");
    std::cout << std::endl;
    if (option > options_.first-1)
    {
        InvalidInput("ERROR : Option not in range 0 to " + std::to_string(options_.first-1)).raise();
    }
    bool exit = false;
    switch (option) 
    {
    case 1:
        revealCredentials();
        break;
    case 2:
        credentialsManager_.addCredentials(inputCredentials());
        break;
    case 3:
        credentialsManager_.updateCredentials(inputCredentials());
        break;
    case 4:
        credentialsManager_.removeCredentials(input<std::string>("Domain"));
        break;
    case 5:
        std::cout << credentialsManager_;
        break;
    case 0:
    default:
        std::cout << "Exit" << std::endl;
        exit = true;
        break;
    }
    return exit;
}

void Controller::revealCredentials()
{
    std::string domain, key;
    bool valid = false;
    while (!valid) 
    {
        try
        {
            domain = input<std::string>("Domain");
            key = input<std::string>("Key");
            valid = true;
        }
        catch (InvalidInput& except)
        {
            std::cout << except.what() << std::endl;
        }
    }
    credentialsManager_.revealCredentials(domain, key);
}

std::unique_ptr<Credentials> Controller::inputCredentials()
{
    std::string domain, password, key;
    bool valid = false;
    while (!valid) 
    {
        try
        {
            domain = input<std::string>("Domain");
            password = input<std::string>("Password");
            key = input<std::string>("Key");
            valid = true;
        }
        catch (InvalidInput& except)
        {
            std::cout << except.what() << std::endl;
        }
    }
    std::cout << std::endl;
    return std::make_unique<Credentials>
        (make_pair(StringToChar(domain), domain.size()),
         make_pair(StringToChar(password), password.size()),
         StringToChar(key));
} 

template<typename T>
T Controller::input(std::string query)
{
    T input;
    std::cout << query << " : " << std::endl << "> ";
    std::cin >> input;
    if (std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore(80,'\n');
        InvalidInput except("ERROR : Invalid Input for \"" + query + "\". Not of type <" + typeid(T).name() + ">");
        except.raise();
    }
    return input;
}