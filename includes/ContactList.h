#ifndef CONTACT_H
#define CONTACT_H

#include "ContractorContact.h"
#include "EmployeeContact.h"


class ContactList {
public:
    ContactList();
    ContactList();
    ~ContactList();

    void Init();
    void ShowAllContacts() const;
    void SearchByName() const;
    void SearchByDepartment() const;


private:
    Contact* FindContact(const Name& target);
    void Insert(Contact* newContact);

    Contact* head;
};





#endif