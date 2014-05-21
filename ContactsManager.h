#ifndef CONTACTSMANAGER_H_
#define CONTACTSMANAGER_H_

#include <iostream>
#include <vector>
#include "Contact.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class ContactsManager {

private:
	vector<Contact> contacts;

public:
	ContactsManager();

	vector<Contact> getContacts() {return contacts;}

	vector<vector<string> > readContacts();
	vector<Contact> rearrangeContacts(vector<vector<string> > contacts);

	void createFile();
	void updateFile();
};


#endif /* CONTACTSMANAGER_H_ */
