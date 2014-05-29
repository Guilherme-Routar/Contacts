#include "ContactsManager.h"

ContactsManager::ContactsManager() {

	try {
		loadContacts();
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

void ContactsManager::loadContacts() {
    
    ifstream file_in;
    
    file_in.open("Contacts.csv");
    
    if(!file_in.fail())
    {
        string line;
        
        //The first line contains the parameters
        getline(file_in, line);
        
        while(file_in.good())
        {
            string name;
            string address;
            string email;
            string number_str;
            
            getline(file_in, line);
            stringstream line_ss(line);
            
            getline(line_ss, name, ',');
            getline(line_ss, address, ',');
            getline(line_ss, email, ',');
            getline(line_ss, number_str, ',');
            
            int number = atoi(number_str.c_str());
            
            Contact* c1 = new Contact(name, address, email, number);
            
            addContact(c1);
        }
        
        file_in.close();
    }
    else
    {
        throw FileNotFound();
    }
    
}

//============================================================================

void ContactsManager::printContacts() const
{
    for (unsigned int i = 0; i < getContacts().size(); i++) {
		cout << *getContacts()[i];
	}
    
    cout << endl << "Num contactos: " << getContacts().size() << endl << endl;
	
}


