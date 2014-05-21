#include <iostream>
#include "Contact.h"
#include "ContactsManager.h"
#include <sstream>

using namespace std;

void mainMenu();

int stringToInt(string str) {
	int n;
	istringstream(str) >> n;
	return n;
}

int main() {
	ContactsManager* A = new ContactsManager();
	mainMenu();
}

void mainMenu() {
	cout << "CONTACTS MANAGER";
}
