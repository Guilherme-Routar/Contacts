#include <iostream>
#include "Contact.h"

using namespace std;

Contact::Contact(string name, string address, string email, int number)
{
	this->name = name;
	this->address = address;
	this->email = email;
	this->number = number;
}

ostream & operator<<(ostream &os, Contact C) {

	os << C.getName() << "," << C.getAddress() << "," << C.getEmail() << "," << C.getNumber() << endl;
	return os;
}
