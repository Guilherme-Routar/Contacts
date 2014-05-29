#ifndef CONTACTSMANAGER_H_
#define CONTACTSMANAGER_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <string>
#include <unordered_set>

#include "Contact.h"
#include "FileNotFound.h"

using namespace std;

struct contactHash
{
    int operator() (const Contact &c1) const
    {
        int sum = 0;
        
        for(int i; i < c1.getName().length(); i++)
        {
            sum = sum + (int)c1.getName()[i];
        }
        
        return sum;
    }
    
    bool operator() (const Contact &c1, const Contact &c2) const
    {
        if(c1.getName().length() != c2.getName().length())
        {
            return false;
        }
        
        for(int i=0; i < c1.getName().length(); i++)
        {
            if(c1.getName()[i] != c2.getName()[i])
            {
                return false;
            }
        }
        
        return true;
    }
    
};

typedef unordered_set<Contact, contactHash, contactHash> HashContact;

//============================================================================

class ContactsManager {

private:
	vector<Contact*> contacts;
    HashContact contactList;

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
