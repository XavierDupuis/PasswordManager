/*  ADDCREDENTIALS
    std::string sDomain, sPassword, sKey;
    std::cout << " Domain   :\n > ";
    std::getline(cin, sDomain, '\n');
    std::cout << " Password :\n > ";
    std::getline(cin, sPassword, '\n');
    std::cout << " Key      :\n > ";
    std::getline(cin, sKey, '\n');

    credentialsManager.addCredentials(make_unique<Credentials>
        (make_pair(StringToChar(sDomain), sDomain.size()),
         make_pair(StringToChar(sPassword), sPassword.size()),
         StringToChar(sKey)));
*/