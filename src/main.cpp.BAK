/*************************************************************************
PROGRAM NAME		PasswordManager

PROGRAMMER			XD

FILE NAME			main.cpp

OTHER FILES			init.h, dataManagement.cpp, dynamicList.cpp, entryManagement.cpp, menu.cpp

DESCRIPTION			Store passwords and domain names in encrypted file
					Can be retrieved or added using a master password

DATE				Started					11 / 05 / 2020
					Version I completed		29 / 05 / 2020

VERSIONS			I : Reading and writing with .txt data file (no encryption)

KNOWN BUGS			NONE
*************************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "init.h"
//#include "Debug\cryptopp820\aes.h"
//#include "Debug\cryptopp820\cryptlib.h"

using namespace std;
//using namespace CryptoPP;

int main() {
	
	cout << " ======== " << PROGRAMNAME << VERSION << "  ======== " << endl << endl;

	CredentialsList credentialsList;
	Credentials credentials;
	
	bool fileLoaded = LoadDataFile(FILENAME, credentialsList);
	cout << " " <<  FILENAME << " loaded : " << boolalpha  << fileLoaded << endl << endl;
	if (!fileLoaded) cout << " A file " << FILENAME << " will be created after this execution." << endl << endl;

	char option = 0;
	bool exit = false;
	unsigned index = 0;

	do {
		DisplayMenu();
		option = ValidCharEntry();
		cout << endl << OptionMenu[int(option-'0')] << endl << endl;
		switch (option) {
		case '1':	//READING FROM LIST
			RevealCredentials(ReadFromList(credentialsList, ValidStringEntry("WANTED DOMAIN"), index));
			break;
		case '2':	//WRITING TO LIST
			WriteToList(credentialsList, EnterCredentials() );
			break;
		case '3':	//CHANGING A PASSWORD
			EditCredentials(credentialsList, EnterCredentials() );
			break;
		case '4':	//REVEAL ALL DATA FROM FILE
			RevealList(credentialsList);
			break;
		case '5':	//ERASING DATA FILE
			DeleteFile(FILENAME, credentialsList);
			break;
		case '0':
			cout << "EXIT CASE" << endl
				 << "SAVING CHANGES..." << endl;
			WriteListToFile(FILENAME, credentialsList);
			exit = true;
			break;
		default :
			cout << "X INVALID OPTION X" << endl;
			break;
		}
		cout << string(3, '\n');
	} while (!exit);

	delete[] credentialsList.credentials;
	credentialsList.credentials = nullptr;

	return 0;
}