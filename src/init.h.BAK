#ifndef INIT
#define INIT

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

extern const std::string	PROGRAMNAME;
extern const char			VERSION;
extern const int			CHARLENGTH;
extern const std::string	FILENAME;
extern const std::string	VALIDCHARACTERS;

enum Option { EXIT, READ, WRITE, EDIT, REVEAL, DELETE, NBOPTIONS };

extern std::string OptionMenu[NBOPTIONS];

/*************************************************************************
 Credentials structure
*************************************************************************/
struct Credentials {
	std::string domain;
	std::string password;
};

/*************************************************************************
 CredentialsList structure
*************************************************************************/
struct CredentialsList {
	Credentials* credentials = new Credentials[0];
	unsigned size = 0;
	unsigned capacity = 0;
};


//////////////////////////////dynamicList.cpp//////////////////////////////
/*************************************************************************
 Increase the capacity of a credentialsList structure list
	\param [in/out]			credentialsList
*************************************************************************/
void IncreaseListCapacity(CredentialsList& credentialsList);

/*************************************************************************
 Tests the capacity of a credentialsList structure
	\param [in/out]		credentialsList
	\return				true if list capacity was increased
*************************************************************************/
extern bool TestListCapacity(CredentialsList& credentialsList);


/////////////////////////////////menu.cpp/////////////////////////////////
/*************************************************************************
 Displays menu options
*************************************************************************/
extern void DisplayMenu();


///////////////////////////entryManagement.cpp///////////////////////////
/*************************************************************************
 Check a string to find space. Repeats if entry outputs an error.
	\param [in]		Char			
	\param [in]		validCharacters	
	\return			true if char is in validCharacters "list"
*************************************************************************/
extern bool ValidCharacter(char Char, std::string validCharacters);

/*************************************************************************
 Check a string to find illegal characters. Repeats if entry outputs an error.
	\param [in/out]		String	(all legal characters prior to error remains)
	\return				true if string contained illegal characters
*************************************************************************/
extern bool FindIllegalsCharacters(std::string& String);

/*************************************************************************
 Check for a valid string entry. Repeats if entry outputs an error.
	\return		entry	 Output of a spaceless valid string
*************************************************************************/
extern std::string ValidStringEntry(std::string input);

/*************************************************************************
 Check for a valid character entry. Repeats if entry outputs an error.
	\return		entry[0] ('Enter' key refers to 0)
*************************************************************************/
extern char ValidCharEntry();


////////////////////////////dataManagement.cpp////////////////////////////
/*************************************************************************
 Loads the data file into a CredentialsList structure
	\param [in]			filename
	\param [in/out]		credentialsList
	\return				true if file was loaded
*************************************************************************/
extern bool LoadDataFile(std::string filename, CredentialsList& credentialsList);

/*************************************************************************
 Look if a domain exist in a CredentialsList.
	\param [in/out]		credentialsList
	\param [in]			wantedDomain
	\param [out]		index
	\return				true if wantedDomain is in credentialsList
*************************************************************************/
extern bool LookForDomain(CredentialsList& credentialsList, std::string wantedDomain, unsigned& index);

/*************************************************************************
 Ask for user domain name and associated password.
	\return		credentials
*************************************************************************/
extern Credentials EnterCredentials();

/*************************************************************************
 Retreives credentials from list associated with domain name.
	\param [in/out]		credentialsList
	\param [in]			domain
	\param [in]			index
	\return				credentials
*************************************************************************/
extern Credentials ReadFromList(CredentialsList& credentialsList, std::string domain, unsigned& index);

/*************************************************************************
 In case the domain doesn't exist, refers to WriteToList function
	\param [in/out]		credentialsList
*************************************************************************/
extern void AddToList(CredentialsList& credentialsList);

/*************************************************************************
 Allows user to edit credentials (change a password)
	\param [in/out]		credentialsList
	\param [in]			editedCredentials
*************************************************************************/
extern void EditCredentials(CredentialsList& credentialsList, Credentials credentials);

/*************************************************************************
 Adds password and domain name to CredentialsList.
	\param [in/out]		credentialsList
	\param [in]			credentials
*************************************************************************/
extern void WriteToList(CredentialsList& credentialsList, Credentials newCredentials);

/*************************************************************************
 Updates credentialsList data file. Writes all credentiels to file.
	\param [in]			credentialsList
	\param [in]			filename
*************************************************************************/
extern void WriteListToFile(std::string filename, CredentialsList& credentialsList);

/*************************************************************************
 Reveal credentials Credentials to the user
	\param [in]			credentials
*************************************************************************/
extern void RevealCredentials(Credentials credentials);

/*************************************************************************
 Reveal all credentials from a credentials list
	\param [in]			credentialsList
*************************************************************************/
extern void RevealList(CredentialsList& credentialsList);

/*************************************************************************
 Remove all data from the data file. Clears the CredentialsList.
	\param [in]			filename
	\param [in/out]		credentialsList
*************************************************************************/
extern void DeleteFile(std::string filename, CredentialsList& credentialsList);

#endif