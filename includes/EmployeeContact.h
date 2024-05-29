#ifndef EMPLOYEECONTACH_H
#define EMPLOYEECONTACH_H

#include "Contact.h"

class EmployeeContact: public Contact{
public:
    static const string DEFAULT_TITLE;
    static const string DEFAULT_DEPARTMENT;

    EmployeeContact();
    EmployeeContact(const string& first_name, const string& last_name, const string& business_phone, const string& email, const int location, const string& title,const string& department);
    virtual ~EmployeeContact();

    virtual void ShowContact() const;
    friend ostream& operator<<(std::ostream& outs, const EmployeeContact& show_me);

    string get_tile() const;
    string get_department() const;
    void set_tile(const string& new_title);
    void set_department(const string& new_department);
    
    
private:
    string title;
    string department;

};

const string EmployeeContact::DEFAULT_TITLE = "Software Engineer";
const string EmployeeContact::DEFAULT_DEPARTMENT = "Engineering";

EmployeeContact::EmployeeContact():Contact(){
    this->title = DEFAULT_TITLE;
    this->department = DEFAULT_DEPARTMENT;
};

EmployeeContact::EmployeeContact(const string& first_name, const string& last_name, const string& business_phone, 
                                const string& email, const int location, const string& title,const string& department)
                                :Contact(first_name, last_name, business_phone, email, location){
    this->title = title;
    this->department = department;
};

EmployeeContact::~EmployeeContact(){
    if (g_debug == true){
        cout << name << "has gone home ..."<< endl;
    }
};

ostream& operator<<(std::ostream& outs, const EmployeeContact& show_me){
    outs << setw(25) << show_me.title << setw(25) << show_me.department << setw(25) << show_me.name << setw(25) << show_me.location << setw(25) << show_me.business_phone << setw(25) << show_me.email << endl;
    return outs;
}


void EmployeeContact::ShowContact() const{
    cout << *this << endl;
};

string EmployeeContact::get_tile() const{
    return title;
};

string EmployeeContact::get_department() const{
    return department;
};

void EmployeeContact::set_tile(const string& new_title){
    this->title = new_title;
};

void EmployeeContact::set_department(const string& new_department){
    this->department = new_department;
};

#endif
