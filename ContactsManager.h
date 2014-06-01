#ifndef CONTACTSMANAGER_H_
#define CONTACTSMANAGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <queue>

#include "Contact.h"
#include "Util.h"
#include "FileNotFound.h"

#define N_SEARCH_RESULTS 5
#define CHAR_ERROR_TOLERANCE 0.25

using namespace std;

struct contactSearch
{
    string contact_name;
    int editDist;
    
    bool operator<(const contactSearch &s1) const
    {
        return editDist > s1.editDist;
    }
    
};

struct contactHash
{
    int operator() (const Contact &c1) const
    {
        int i = 0;
        int sum = 0;
        string name_key = c1.getName();
        name_key = util::strToLower(name_key);
        
        for(i = 0; i < name_key.length(); i++)
        {
            sum = sum + (int)name_key[i];
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
            if(tolower(c1.getName()[i]) != tolower(c2.getName()[i]))
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
	HashContact getContacts() const;
    
    /**
	 * * Creates a contact
	 */
	void createContact();
    
	/**
	 * Removes contact from the contact list
	 */
	void removeContact();
    
    /**
     * Search contact on the contact list
     */
    void searchContact();
    
    /**
     * Generates search suggestions
     */
    void searchHelper(string &search_input);

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
