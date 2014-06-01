#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>

using namespace std;

class Contact {

private:
	string name, address, email;
	int number;

public:
    
    /**
     * Constructor
     */
	Contact(string name, string address, string email, int number);

	/**
     * Get Methods
     */
	string getName() const {return name;}
	string getAddress() const {return address;}
	string getEmail() const {return email;}
	int getNumber() const {return number;}

    /**
     * Set Methods
     */
	void setName(string n) {name = n;}
	void setAddress(string m) {address = m;}
	void setEmail(string e) {email = e;}
	void setNumber(int u) {number = u;}

    /**
     * Operator <<
     */
	friend ostream & operator<<(ostream &os, Contact out_cont);

};


#endif /* CONTACT_H_ */
