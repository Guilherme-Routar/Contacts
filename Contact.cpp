#include "Contact.h"

Contact::Contact(string name, string address, string email, int number)
{
	this->name = name;
	this->address = address;
	this->email = email;
	this->number = number;
}

//============================================================================

ostream & operator<<(ostream &os, Contact out_cont) {

	os << out_cont.getName() << "," << out_cont.getAddress() << "," << out_cont.getEmail() << "," << out_cont.getNumber() << endl;
    
	return os;
}

//============================================================================
