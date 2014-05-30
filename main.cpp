#include <iostream>
#include <sstream>
#include <stdlib.h>

#include "Contact.h"
#include "ContactsManager.h"

using namespace std;

void mainMenu(ContactsManager &contManag) {
    
	int option;
    string option_str;
    bool quit_menu = false;
    
	while (!quit_menu) {
        
		cout << endl << "########################" << endl
        << "#   CONTACTS MANAGER   #" << endl
        << "########################" << endl << endl;
        
		cout << "[1] Search contact" << endl
        << "[2] Add contact" << endl
        << "[3] Remove contact" << endl
        << "[4] Print Contact List" << endl
        << "[5] Exit" << endl << endl;
        
		getline(cin, option_str);
        option = atoi(option_str.c_str());
        
		switch(option) {
            case 1: //Search contact
                break;
            case 2: //Add contact
                contManag.createContact();
                break;
            case 3: //Remove contact
                contManag.removeContact();
                break;
            case 4:
                contManag.printContacts();
                break;
            case 5: //Exit
                quit_menu = true;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
		}
	}
}

//============================================================================

int main() {

	ContactsManager* contManag = new ContactsManager();

	mainMenu(*contManag);
    
    delete contManag;
    
    return 0;
    
}


