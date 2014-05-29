#include "ContactsManager.h"

using namespace std;

int stringToInt(string str);

ContactsManager::ContactsManager() {

	try {
		updateContacts();
	}
	catch(FileNotFound &F) {
		createFile();
	}
}

//============================================================================

ContactsManager::~ContactsManager() {

	for (unsigned int i = 0; i < contacts.size(); i++) delete contacts[i];
}

//============================================================================

vector<Contact*> ContactsManager::getContacts() const
{
    return contacts;
}

//============================================================================

vector<vector<string> > ContactsManager::readContacts() const{

	vector<vector<string> > vec;
	vector <string> subVec;
	ifstream file("Contacts.csv");
	string line;

	//The first line contains the parameters
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

//============================================================================

vector<Contact*> ContactsManager::rearrangeContacts(vector<vector<string> > contacts_) {

	vector<Contact*> vec;

	for (unsigned int i = 0; i < contacts_.size(); i++) {

		string name = contacts_[i][0];
		string address = contacts_[i][1];
		string email = contacts_[i][2];
		string str_number = contacts_[i][3];
		int number = stringToInt(str_number);

		Contact* C = new Contact(name, address, email, number);
		vec.push_back(C);
	}

	contacts = vec;

	return vec;
}

//============================================================================

void ContactsManager::addContact(Contact* C) {

	contacts.push_back(C);

	updateFile();
}

//============================================================================

void ContactsManager::removeContact(int pos) {

	delete contacts[pos];
	contacts.erase(contacts.begin() + pos);

	updateFile();
}

//============================================================================

void ContactsManager::removeContactInterf() {

	string name;
	cout << "Insert the name: ";
	cin.ignore();
	getline(cin, name);

	for (unsigned int i = 0; i < contacts.size(); i++) {
		if (contacts[i]->getName() == name) {
			removeContact(i);
			return;
		}
	}

	cout << "Name not found." << endl;
}

//============================================================================

void ContactsManager::createContact() {

	//Adicionar uma verificacao para nome/numero/email ja existente

	string name;
	cout << "Insert a name: ";
	cin.ignore();
	getline(cin, name);

	string address;
	cout << "Insert an address: ";
	getline(cin, address);

	string email;
	cout << "Insert an email: ";
	getline(cin, email);

	int number;
	cout << "Insert a phone number: ";
	cin >> number;

	Contact* temp = new Contact(name, address, email, number);
	addContact(temp);

	cout << "Contact created sucessfully." << endl;
}

//============================================================================

void ContactsManager::createFile() const {

	ofstream file("Contacts.csv");
	file << "nome,morada,email,telefone";
}

//============================================================================

void ContactsManager::updateFile() {

	ofstream file("Contacts.csv");

	if (file) {

		file << "nome,morada,email,telefone" << endl;

		for (unsigned int i = 0; i < contacts.size(); i++) {
			file << *contacts[i];
		}
	}
	else throw FileNotFound();
}

//============================================================================

void ContactsManager::updateContacts() {

	vector<vector<string> > vec = readContacts();
	vector<Contact*> vec2 = rearrangeContacts(vec);

	contacts = vec2;
}
