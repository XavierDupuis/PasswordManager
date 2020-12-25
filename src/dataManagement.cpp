#include "init.h"

using namespace std;

/*************************************************************************
 Loads the data file into a CredentialsList structure
	\param [in]			filename
	\param [in/out]		credentialsList
	\return				true if file was loaded
*************************************************************************/
bool LoadDataFile(string filename, CredentialsList& credentialsList) {
	ifstream file(filename);
	if (file.fail()) {
		return false;
	}
	while (!ws(file).eof()) {
		TestListCapacity(credentialsList);
		Credentials credentials;
		file >> credentials.domain >> credentials.password;
		credentialsList.credentials[credentialsList.size++] = credentials;
	}
	file.close();
	return true;
}

/*************************************************************************
 Look if a domain exist in a CredentialsList.
	\param [in/out]		credentialsList
	\param [in]			wantedDomain
	\param [out]		index
	\return				true if wantedDomain is in credentialsList
*************************************************************************/
bool LookForDomain(CredentialsList& credentialsList, string wantedDomain, unsigned& index) {
	for (unsigned i = 0; i < credentialsList.size; i++) {
		if (credentialsList.credentials[i].domain == wantedDomain) {
			index = i;
			return true;
		}
	}
	return false;
}

/*************************************************************************
 Ask for user domain name and associated password.
	\return		credentials
*************************************************************************/
Credentials EnterCredentials() {
	return { ValidStringEntry("DOMAIN"), ValidStringEntry("PASSWORD") };
}

/*************************************************************************
 Retreives credentials from list associated with domain name.
	\param [in/out]		credentialsList
	\param [in]			domain
	\param [in]			index
	\return				credentials
*************************************************************************/
Credentials ReadFromList(CredentialsList& credentialsList, string domain, unsigned& index) {
	if (LookForDomain(credentialsList, domain, index)) {
		return credentialsList.credentials[index];
	}
	else {
		AddToList(credentialsList);
		}
		return { domain,"NULL" };
	}

/*************************************************************************
 In case the domain doesn't exist, refers to WriteToList function
	\param [in/out]		credentialsList
*************************************************************************/
void AddToList(CredentialsList& credentialsList) {
	cout << endl << " ERROR : Could not find domain in " << FILENAME
		 << endl << " Would you like to add these credentials to the list? (Y/N) " << endl << endl;
	char option = ValidCharEntry();
	cout << endl;
	if (tolower(option) == 'y' || tolower(option) == 'yes') {
		WriteToList(credentialsList, EnterCredentials());
	}
}

/*************************************************************************
 Allows user to edit credentials (change a password)
	\param [in/out]		credentialsList
	\param [in]			editedCredentials
*************************************************************************/
void EditCredentials(CredentialsList& credentialsList, Credentials editedCredentials) {
	unsigned index;
	if (LookForDomain(credentialsList, editedCredentials.domain, index)) {
		ReadFromList(credentialsList, editedCredentials.domain, index);
		credentialsList.credentials[index] = editedCredentials;
		cout << " Password sucessfully changed for domain " << editedCredentials.domain << endl << endl;
	}
}

/*************************************************************************
 Adds password and domain name to CredentialsList.
	\param [in/out]		credentialsList
	\param [in]			credentials
*************************************************************************/
void WriteToList(CredentialsList& credentialsList, Credentials newCredentials) {
	unsigned index;
	if (LookForDomain(credentialsList, newCredentials.domain, index)) {
		cout << " ERROR : Domain name already registered in " << FILENAME
			 << endl << " Would you like to edit these credentials? (Y/N) " << endl << endl;
		char option = ValidCharEntry();
		cout << endl;
		if (tolower(option) == 'y' || tolower(option) == 'yes') {
			EditCredentials(credentialsList, newCredentials);
		}
	}
	else {
		TestListCapacity(credentialsList);
		credentialsList.credentials[credentialsList.size++] = newCredentials;
	}
	cout << " Credentials sucessfully recorded. " << endl
		 << " Will be written at program's termination." << endl << endl;
}

/*************************************************************************
 Updates credentialsList data file. Writes all credentiels to file.
	\param [in]			credentialsList
	\param [in]			filename
*************************************************************************/
void WriteListToFile(string filename, CredentialsList& credentialsList) {
	ofstream file(filename, ios::trunc);
	for (unsigned i = 0; i < credentialsList.size; i++) {
		file << credentialsList.credentials[i].domain << " "
			<< credentialsList.credentials[i].password << endl;
	}
	file.close();
}

/*************************************************************************
 Reveal Credentials to the user
	\param [in]			credentials
*************************************************************************/
void RevealCredentials(Credentials credentials) {
	cout << credentials.domain << " : " << credentials.password << endl;
}

/*************************************************************************
 Reveal all credentials from a credentials list
	\param [in]			credentialsList
*************************************************************************/
void RevealList(CredentialsList& credentialsList) {
	for (unsigned i = 0; i < credentialsList.size; i++) {
		RevealCredentials(credentialsList.credentials[i]);
	}
}

/*************************************************************************
 Remove all data from the data file. Clears the CredentialsList.
	\param [in]			filename
	\param [in/out]		credentialsList
*************************************************************************/
void DeleteFile(string filename, CredentialsList& credentialsList) {
	cout << " Do you really want to erase all data from " << FILENAME << " ?" << endl;
	string answer = ValidStringEntry(" Type ERASE to erase all data ");
	cout << endl << endl;
	if (answer == "ERASE") {
		cout << " ERASING FILE..." << endl;

		delete[] credentialsList.credentials;
		credentialsList.credentials = nullptr;

		CredentialsList newCredentialsList;
		credentialsList = newCredentialsList;

		ofstream file(filename, ios::trunc);
		file.close();
		cout << " FILE ERASED." << endl;
	}
	//cin.ignore();
}