#ifndef CONTACTSMANAGER_H_
#define CONTACTSMANAGER_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "Contact.h"

using namespace std;

class ContactsManager {

private:
	vector<Contact*> contacts;

public:
    
	/**
	 * Class constructor
	 */
	ContactsManager();
    
	/**
	 * Class destructor
	 */
	~ContactsManager();
    
	/**
	 * Returns the contacts
	 */
	vector<Contact*> getContacts() const;

	/**
	 * Reads contacts from the csv file and stores them in a 2d vector
	 */
	vector<vector<string> > readContacts() const;
    
	/**
	 * Arranges the contacts in the standard form
	 */
	vector<Contact*> rearrangeContacts(vector<vector<string> > contacts);
    
	/**
	 * Adds contact C to the contacts
	 */
	void addContact(Contact* C);
    
	/**
	 * Removes contact C from the contacts
	 */
	void removeContact(int pos);
    
	/**
	 * Removes a contact
	 */
	void removeContactInterf();
    
	/**
	 * * Creates a contact
	 */
	void createContact();

	/**
	 * Creates the csv file
	 */
	void createFile() const;
    
	/**
	 * Updates the csv file with the current contacts
	 */
	void updateFile();
    
	/**
	 * Updates the contacts
	 */
	void updateContacts();

};


#endif /* CONTACTSMANAGER_H_ */
