#include "../../src/AES.h"
#include "../../src/Utility.h"
#include "../../src/FileHandler.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int main()
{
    std::cout << "MAIN" << std::endl;

    CredentialsManager credentialsManager;
    FileHandler fileHandler = FileHandler("data.txt");
    fileHandler.readFile(credentialsManager);
    std::cout << credentialsManager;

    unsigned char plain[] = { 'A', 'B', 'C', 'D', 
                              'E', 'F', 'G', 'H', 
                              'I', 'J', 'K', 'L', 
                              'M', 'N', 'O', 'P',  }; //plaintext example
    unsigned char splain[] = { 'A', 'B', 'C', 'D'  }; //plaintext example
    /*Credentials cred1 = Credentials(make_pair(plain, 16), make_pair(splain, 4));
    Credentials cred2 = Credentials(make_pair(splain, 4), make_pair(plain, 16));
    credentialsManager.addCredentials(cred1);
    credentialsManager.addCredentials(cred2);*/

    /*std::string domain1 = "Polytechnique";
    std::string key1 = "veryBadPassword";
    Credentials cred3 = Credentials(make_pair(StringToChar(domain1), domain1.size()), make_pair(StringToChar(key1), key1.size()));
    credentialsManager.addCredentials(cred3);*/

    /*std::cout << "cred1 : " << cred1;
    std::cout << "cred2 : " << cred2;
    std::cout << "cred3 : " << cred3;
    fileHandler.writeFile(credentialsManager);*/

    unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }; //key example
    unsigned int plainLen = 16;  //bytes in plaintext
    unsigned int outLen = 0;  // out param - bytes in сiphertext

    std::cout << std::dec;
    AES aes(128);  //128 - key length, can be 128, 192 or 256
    unsigned char* c = aes.EncryptECB(plain, plainLen * sizeof(unsigned char), key, outLen);
    unsigned char* d = aes.DecryptECB(c, plainLen * sizeof(unsigned char), key);
    std::cout << "outLen : " << outLen << std::endl;
    std::cout << "cString : " << CharToString(c, outLen) << " : " << CharToString(c, outLen).size() << std::endl;
    std::cout << "dString : " << CharToString(d, outLen) << " : " << CharToString(d, outLen).size() << std::endl;

    std::ofstream f("test.txt");

    AES encryption(128);
    std::string stringk = "SecurePasswordEncrypter";
    std::string stringkey = "asdfg"; //"h(7*HE'u7vSw_$!F";
    unsigned int outLenk = 0;
    unsigned char* k = encryption.EncryptECB(StringToChar(stringk), stringk.size() * sizeof(unsigned char), StringToChar(stringk), outLenk);
    unsigned char* l = encryption.DecryptECB(k, stringk.size() * sizeof(unsigned char), StringToChar(stringk));
    std::cout << "kString : " << CharToString(k, outLenk) << " : " << CharToString(k, outLenk).size() << std::endl;
    std::cout << "lString : " << CharToString(l, outLenk) << " : " << CharToString(l, outLenk).size() << std::endl;
    unsigned char* ptr = l;
    for(unsigned i = 0; i < stringk.size(); i++)
    {
        std::cout << *ptr++ << " ";
    }
    std::cout << " END" << std::endl;
    unsigned char* ptr2 = l;
    for(unsigned i = 0; i < outLenk; i++)
    {
        std::cout << *ptr2++ << " ";
        f << (unsigned)*ptr2 << " ";
    }
    std::cout << " END" << std::endl;
    f << " END" << std::endl;
    //delete k;
    //delete l;

    AES user(128);
    std::string stringUser, stringKey;
    std::getline(cin, stringUser, '\n');
    std::getline(cin, stringKey, '\n');
    //std::cin >> stringUser >> stringKey;
    unsigned int outLenUser = 0;
    unsigned char* m = user.EncryptECB(StringToChar(stringUser), stringUser.size() * sizeof(unsigned char), StringToChar(stringKey), outLenUser);
    unsigned char* n = user.DecryptECB(m, stringUser.size() * sizeof(unsigned char), StringToChar(stringKey));
    std::cout << "encryptedUser : " << CharToString(m, outLenUser) << " : " << CharToString(m, outLenUser).size() << " : " << outLenUser << std::endl;
    std::cout << "decryptedUser : " << CharToString(n, outLenUser) << " : " << CharToString(n, outLenUser).size() << std::endl;
    for(unsigned j = 0; j < outLenUser; j++)
    {
        std::cout << *n++ << " ";
        f << (unsigned)*n << " ";
    }
    std::cout << " END" << std::endl;
    f << " END" << std::endl;
    for(unsigned j = 0; j < stringUser.size(); j++)
    {
        std::cout << stringUser[j] << " ";
    }
    std::cout << " END" << std::endl;
    //delete[] m;
    //delete[] n;
/*
    std::cout << "Plaintext : ";
    for (auto& it : plain)
    {
        std::cout << it;
    }
    std::cout << std::endl;

    std::cout << "Encryptedtext : ";
    for (unsigned i = 0; i < plainLen; i++)
    {
        std::cout << *c++;
    }
    std::cout << std::endl;

    std::cout << "Decryptedtext : ";
    for (unsigned i = 0; i < plainLen; i++)
    {
        std::cout << *d++;
    }
    std::cout << std::endl;

    std::cout << "TEST WRITE ALPHA : ";
    unsigned char a = 0x00;
    vector<unsigned> write;
    std::ofstream f("data.txt");
    for (; a < 0xFF; a++)
    {
        std::cout << a << " ";
        write.push_back(a);
        f << std::setfill('0') << std::uppercase << std::setw(2) << std::hex << write[a] << " ";
    }
    f.close();
    std::cout << std::endl;

    std::cout << "TEST READ ALPHA : ";
    unsigned b;
    vector<unsigned char> read;
    std::ifstream f2("data.txt");
    while (f2 >> std::hex >> b)
    {
        std::cout << unsigned(b) << " ";
        read.push_back(b);
    }
    std::cout << "read[67] : " << read[67] << " ";
    f2.close();

    std::cout << std::endl;
*/
    return 0;
}