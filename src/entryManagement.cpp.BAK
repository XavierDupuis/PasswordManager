#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "init.h"

using namespace std;

/*************************************************************************
 Check a string to find space. Repeats if entry outputs an error.
	\param [in]		Char
	\param [in]		validCharacters
	\return			true if char is in validCharacters "list"
*************************************************************************/
bool ValidCharacter(char Char, string validCharacters) {
	for (unsigned i = 0; i < validCharacters.size(); i++) {
		if (tolower(Char) == validCharacters[i]) {
			return true;
		}
	}
	return false;
}

/*************************************************************************
 Check a string to find illegal characters. Repeats if entry outputs an error.
	\param [in/out]		String	(all legal characters prior to error remains)
	\return				true if string contained illegal characters
*************************************************************************/
bool FindIllegalsCharacters(string& String) {
	string newString;
	for (unsigned i = 0; i < String.size(); i++) {
		if (!ValidCharacter(String[i], VALIDCHARACTERS)) {
			String = newString;
			return true;
		}
		newString += String[i];
	}
	return false;
}

/*************************************************************************
 Check for a valid string entry. Repeats if entry outputs an error.
	\return		entry	 Output of a valid string
*************************************************************************/
string ValidStringEntry(string input) {
	bool entryError;
	string entry;
	do {
		cout << " " << input << " : " << endl << endl;
		entryError = false;
		getline(cin, entry);
		if (cin.fail()) {
			entryError = true;
			cout << endl << " ERROR : Could not read string. " << endl << endl;
			cin.clear();
			//cin.ignore(entry.size());
		}
		else {
			entryError = FindIllegalsCharacters(entry);
			if (entryError) {
				cout << endl << " ERROR : String cannot contain illegal characters. " << endl
					<< endl << " Valid characters are : " << VALIDCHARACTERS << endl << endl;
			}
		}
	} while (entryError);
	cout << endl;
	return entry;
}

/*************************************************************************
 Check for a valid character entry. Repeats if entry outputs an error.
	\return		entry[0] ('Enter' key refers to 0)
*************************************************************************/
char ValidCharEntry() {
	bool entryError = false;
	string entry;
	do {
		getline(cin, entry);
		if (cin.fail()) {
			entryError = true;
			cout << endl << " ERROR : Could not read character. " << endl << endl;
			cin.clear();
			//cin.ignore(entry.size());
		}
		else if (entry[0] == 0) {
			entryError = false;
			entry[0] = '0';
		}
		else if (entry.size() != 1) {
			entryError = true;
			cout << endl << " ERROR : Too many characters. " << endl << endl;
			cin.clear();
		}
		else {
			entryError = false;
		}
	} while (entryError);
	return entry[0];
}