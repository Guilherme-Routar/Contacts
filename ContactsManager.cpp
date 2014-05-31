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
    
    saveContacts();
    
}

//============================================================================

HashContact ContactsManager::getContacts() const
{
    return contactList;
}

//============================================================================

void ContactsManager::removeContact() {

	string name;
	cout << endl << "Insert the name: ";
	getline(cin, name);
    
    Contact c1(name,"","",0);
    HashContact::const_iterator itf = contactList.find(c1);
    
    if(itf != contactList.end())
    {
        contactList.erase(itf);
        cout << endl<< "Contact found and deleted." << endl;
    }
    else
    {
        cout << "Contact not found." << endl;
    }
    
}

//============================================================================

void ContactsManager::searchContact() {
    
	string name;
    bool quit_search = false;
    
    while(!quit_search)
    {
        cout << endl << endl << "Search: ";
        getline(cin, name);
        
        Contact c1(name,"","",0);
        HashContact::const_iterator itf = contactList.find(c1);
        
        if(itf != contactList.end())
        {
            cout << endl << "Contact found: " << *itf << endl;
            quit_search = true;
        }
        else if(name == "")
        {
            quit_search = true;
        }
        else
        {
            cout << endl << "Did you mean: ";
            searchHelper(name);
        }
    }
    
}

//============================================================================

void ContactsManager::searchHelper(string &search_input)
{
    priority_queue<contactSearch> search_queue;
    
    HashContact::const_iterator it = contactList.begin();
    
    string pattern = util::strToLower(search_input);
    
    while(it != contactList.end())
    {
        string text = (*it).getName();
        text = util::strToLower(text);
        
        contactSearch search_cand;
        search_cand.contact_name = (*it).getName();
        search_cand.editDist = util::minEditDistance(pattern, text);
        
        search_queue.push(search_cand);
        
        it++;
    }
    
    int i = 0;
    
    while(!search_queue.empty() && (i < N_SEARCH_RESULTS))
    {
        contactSearch temp;
        temp = search_queue.top();
        search_queue.pop();
        
        if(temp.editDist > MAX_EDIT_DIST)
        {
            break;
        }
        
        cout << endl << temp.contact_name;
        
        i++;
    }
    
}

//============================================================================

void ContactsManager::createContact() {

	string name;
    bool input_check = false;

    while(!input_check)
    {
        cout << "Insert a name: ";
        getline(cin, name);
        
        if(name == "")
        {
            cout << endl << "Invalid Contact Name." << endl;
        }
        else
        {
            input_check = true;
        }
    }

	string address;
	cout << "Insert an address: ";
	getline(cin, address);

	string email;
	cout << "Insert an email: ";
	getline(cin, email);

    int number = 0;
	input_check = false;
    
    while(!input_check)
    {
        cout << "Insert a phone number: ";
        
        if(cin >> number)
        {
            cin.ignore(1000,'\n');
            input_check = true;
        }
        else
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout << endl << "Invalid Phone Number." << endl;
        }
        
    }
    
    //Adicionar uma verificacao para nome/numero/email ja existente
    Contact c1(name,"","",0);
    HashContact::const_iterator itf = contactList.find(c1);
    
    if(itf == contactList.end())
    {
        Contact temp(name, address, email, number);
        contactList.insert(temp);
        cout << endl << "Contact created sucessfully." << endl;
    }
    else
    {
        cout << endl << "Contact already exists." << endl;
    }
	
}

//============================================================================

void ContactsManager::createFile() const {

	ofstream file("Contacts.csv");
	file << "nome,morada,email,telefone";
}

//============================================================================

void ContactsManager::saveContacts() {
    
    ofstream file_out;
    
    if(getContacts().size() != 0)
    {
        file_out.open("Contacts.csv");
        
        if(file_out.fail())
        {
            throw FileNotFound();
        }
        
        file_out << "nome,morada,email,telefone" << endl;
        
        HashContact::const_iterator it = contactList.begin();
        
        while(it != contactList.end())
        {
            file_out << *it;
            it++;
            
            if(it != contactList.end())
            {
                file_out << endl;
            }
            
        }
        
        file_out.close();
        
    }
    else
    {
        remove("Contacts.csv");
    }
    
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
            
            Contact c1(name, address, email, number);
            
            contactList.insert(c1);
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
    HashContact::const_iterator it = contactList.begin();
    
    while(it != contactList.end())
    {
        cout << *it << endl;
        it++;
    }
    
    cout << endl << "Num contactos: " << getContacts().size() << endl << endl;
	
}
