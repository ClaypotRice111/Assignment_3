#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H


#include "ContactList.h"


class AddressBook {
public:
    static const string DEFAULT_COMPANY_NAME;

    AddressBook();
    AddressBook(const string& company_name);
    ~AddressBook();

    void Init();
    void Run();

private:
    void Menu();
    int GetUserOption();
    void ShowAllcontacts();
    void SearchByName();
    void SearchByDepartment();
    void Quit();

    string company_name;
    ContactList contact_list;
};

const string AddressBook::DEFAULT_COMPANY_NAME = "TP Communications";

AddressBook::AddressBook(){
    this->company_name = DEFAULT_COMPANY_NAME;
};

AddressBook::AddressBook(const string& company_name){
    this->company_name = company_name;
};

AddressBook::~AddressBook(){
    if (g_debug){
        cout << "addressbook closed..." <<endl;
    }
};

void AddressBook::Init(){
    contact_list.Init();
};

void AddressBook::Run(){
    int option;
    do {
        Menu();
        option = GetUserOption();
        switch (option) {
            case 1: ShowAllcontacts(); break;
            case 2: SearchByName(); break;
            case 3: SearchByDepartment(); break;
            case 4: Quit(); break;
            default: std::cout << "Invalid option. Please try again.\n";
        }
    } while (option != 4);
};

void AddressBook::Menu(){
    cout << company_name << " Address Book Menu\n";
    cout << "1. View all contacts\n";
    cout << "2. Search by name\n";
    cout << "3. Search by department\n";
    cout << "4. Quit\n";
    cout << "Select an option (1-4): ";
};

int AddressBook::GetUserOption(){
    int option;
    cin >> option;
    return option;
};

void AddressBook::ShowAllcontacts(){
    contact_list.ShowAllContacts();
};

void AddressBook::SearchByName(){
    string first_name, last_name;
    cout << "Enter a contact first name: ";
    cin >> first_name;
    cout << "Enter a contact last name: ";
    cin >> last_name;
    contact_list.SearchByName(Name(first_name, last_name));
};

void AddressBook::SearchByDepartment(){
    string department;
    cout << "Enter a department: ";
    cin >> department;
    contact_list.SearchByDepartment(department);
};

void AddressBook::Quit(){
    cout << "Thanks for using our AddressBook. See you again!\n";
};

#endif 