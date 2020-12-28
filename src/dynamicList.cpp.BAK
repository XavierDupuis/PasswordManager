#include "init.h"

using namespace std;

/*************************************************************************
 Increase the capacity of a credentialsList structure list
	\param [in/out]		credentialsList
*************************************************************************/
void IncreaseListCapacity(CredentialsList& credentialsList) {
	if (credentialsList.capacity < 1) {
		credentialsList.capacity = 1;
	}
	else {
		credentialsList.capacity = 2 * credentialsList.size;
	}
	Credentials* newCredentials = new Credentials[credentialsList.capacity];
	for (unsigned i = 0; i < credentialsList.size; i++) {
		newCredentials[i] = credentialsList.credentials[i];
		credentialsList.credentials[i] = { "","" };
	}

	delete[] credentialsList.credentials;
	credentialsList.credentials = newCredentials;
	newCredentials = nullptr;
}

/*************************************************************************
 Tests the capacity of a credentialsList structure
	\param [in/out]		credentialsList
	\return				true if list capacity was increased
*************************************************************************/
bool TestListCapacity(CredentialsList& credentialsList) {
	if (credentialsList.size == credentialsList.capacity) {
		IncreaseListCapacity(credentialsList);
		return true;
	}
	return false;
}