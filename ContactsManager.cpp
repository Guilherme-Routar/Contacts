#include "ContactsManager.h"
#include <iostream>
#include <string>
#include "Contact.h"
#include <vector>
#include "FileNotFound.h"

using namespace std;

int stringToInt(string str);

ContactsManager::ContactsManager() {

	try {
		vector<vector<string> > vec = readContacts();
		vector<Contact> vec2 = rearrangeContacts(vec);
	}
	catch(FileNotFound &F) {
		createFile();
	}

	for (unsigned int i = 0; i < contacts.size(); i++) {
		cout << contacts[i];
	}
}

vector<vector<string> > ContactsManager::readContacts() {

	vector<vector<string> > vec;
	vector <string> subVec;
	ifstream file("Contacts.csv");
	string line;

	//The first line has the parameters
	getline(file, line);

	while (!file.eof())
	{
		if (file)
		{
			if (!getline(file, line)) break;

			istringstream content(line);
			subVec.clear();

			while (content)
			{
				string subContent;
				if (!getline(content, subContent, ',')) break;
				subVec.push_back(subContent);
			}

			vec.push_back(subVec);
		}
		else {
			vec.clear();
			throw FileNotFound();
			break;
		}
	}

	return vec;
}

vector<Contact> ContactsManager::rearrangeContacts(vector<vector<string> > contacts_) {

	vector<Contact> vec;

	for (unsigned int i = 0; i < contacts_.size(); i++) {

		string name = contacts_[i][0];
		string address = contacts_[i][1];
		string email = contacts_[i][2];
		string str_number = contacts_[i][3];
		int number = stringToInt(str_number);

		Contact C(name, address, email, number);

		vec.push_back(C);
	}

	contacts = vec;

	return vec;
}

void ContactsManager::createFile() {

	ofstream file("Contacts.csv");
	file << "nome, morada, email, telefone";

}

void ContactsManager::updateFile() {

	ofstream file("Contacts.csv");
	file.open("Contactos.csv", ios_base::app);

	for (unsigned int i = 0; i < contacts.size(); i++) {
		file << contacts[i];
	}
}
