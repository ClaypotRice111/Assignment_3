#ifndef EMPLOYEECONTACH_H
#define EMPLOYEECONTACH_H

#include "Contact.h"

class EmployeeContact : public  Contact  {
public:

    EmployeeContact();
    EmployeeContact(const string& title, const string& department, const string& first_name, const string& last_name, const string& business_phone, const string& email,const int& loaction);
    ~EmployeeContact();

    virtual void ShowContact() const;

    string get_tile() const;
    string get_department() const;
    void set_tile();
    void set_department();
    
private:
    string title;
    string department;

};


#endif
