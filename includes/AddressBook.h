#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H


#include "ContactList.h"


class AddressBook {
public:

    AddressBook();
    AddressBook();
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

#endif 