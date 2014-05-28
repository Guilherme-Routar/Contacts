#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>

using namespace std;

class Contact {

private:
	string name, address, email;
	int number;

public:
	Contact(string name, string address, string email, int number);

	//Get and set methods
	string getName() {return name;}
	string getAddress() {return address;}
	string getEmail() {return email;}
	int getNumber() {return number;}

	void setName(string n) {name = n;}
	void setAddress(string m) {address = m;}
	void setEmail(string e) {email = e;}
	void setNumber(int u) {number = u;}

	friend ostream & operator<<(ostream &os, Contact C);

};




#endif /* CONTACT_H_ */
