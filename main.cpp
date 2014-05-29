#include <iostream>
#include <sstream>
#include <stdlib.h>

#include "Contact.h"
#include "ContactsManager.h"

using namespace std;

void mainMenu(ContactsManager A);

int stringToInt(string str) {
	int n;
	istringstream(str) >> n;
	return n;
}

int main() {

	ContactsManager A;
	vector<Contact*> vec = A.getContacts();

    cout <<"Num contactos: " << vec.size() << endl;
	for (unsigned int i = 0; i < vec.size(); i++) {
		cout << *vec[i];
	}
	cout << endl << endl;

	mainMenu(A);
}

void mainMenu(ContactsManager A) {

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
			A.createContact();
			break;
		case '3': //Remove contact
			A.removeContactInterf();
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
