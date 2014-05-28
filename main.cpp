#include <iostream>
#include "Contact.h"
#include "ContactsManager.h"
#include <sstream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

void mainMenu(ContactsManager A);

int stringToInt(string str) {
	int n;
	istringstream(str) >> n;
	return n;
}

void clearScreen()
{
    COORD upperLeftCorner = {0,0};
    DWORD charsWritten;
    DWORD conSize;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO  csbi;

    GetConsoleScreenBufferInfo(hCon, &csbi);
    conSize = csbi.dwSize.X * csbi.dwSize.Y;

    // fill with spaces
    FillConsoleOutputCharacter(hCon, TEXT(' '), conSize, upperLeftCorner, &charsWritten);
    GetConsoleScreenBufferInfo(hCon, &csbi);
    FillConsoleOutputAttribute(hCon, csbi.wAttributes, conSize, upperLeftCorner, &charsWritten);

    // cursor to upper left corner
    SetConsoleCursorPosition(hCon, upperLeftCorner);
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
