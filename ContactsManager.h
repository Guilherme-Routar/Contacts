#ifndef CONTACTSMANAGER_H_
#define CONTACTSMANAGER_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <string>

#include "Contact.h"
#include "FileNotFound.h"

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
	 * Save to an csv file the current contacts in ContactManager
	 */
	void saveContacts();
    
	/**
	 * Loads the contacts from a csv file to the ContactManager
	 */
	void loadContacts();
    
    /**
     * Prints all contacts
     */
    void printContacts() const;

};


#endif /* CONTACTSMANAGER_H_ */
