#include "../../src/AES.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int main()
{
    unsigned char plain[] = { 'A', 'B', 'C', 'D', 
                              'E', 'F', 'G', 'H', 
                              'I', 'J', 'K', 'L', 
                              'M', 'N', 'O', 'P' }; //plaintext example
    unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }; //key example
    unsigned int plainLen = 16;  //bytes in plaintext
    unsigned int outLen = 0;  // out param - bytes in сiphertext

    AES aes(128);  //128 - key length, can be 128, 192 or 256
    unsigned char* c = aes.EncryptECB(plain, plainLen * sizeof(unsigned char), key, outLen);
    unsigned char* d = aes.DecryptECB(c, plainLen * sizeof(unsigned char), key);
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
    return 0;
}