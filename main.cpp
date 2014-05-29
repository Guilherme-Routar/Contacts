#include <iostream>
#include <sstream>
#include <stdlib.h>

#include "Contact.h"
#include "ContactsManager.h"

using namespace std;

void mainMenu(ContactsManager contManag) {
    
	char option;
    
	while (true) {
        
		cout << "########################" << endl
        << "#   CONTACTS MANAGER   #" << endl
        << "########################" << endl << endl;
        
		cout << "[1] Search contact" << endl
        << "[2] Add contact" << endl
        << "[3] Remove contact" << endl
        << "[4] Exit" << endl << endl;
        
		cin >> option;
        
		switch(option) {
            case '1': //Search contact
                break;
            case '2': //Add contact
                contManag.createContact();
                break;
            case '3': //Remove contact
                contManag.removeContactInterf();
                break;
            case '4': //Exit
                exit(0);
                break;
            default:
                cout << "Invalid option." << endl;
                break;
		}
	}
}

//============================================================================

int main() {

	ContactsManager contManag;

    cout <<"Num contactos: " << contManag.getContacts().size() << endl;

	mainMenu(contManag);
    
}


