#ifndef CONTACR
#define CONTACR

#include <iostream>
#include <string>
#include <iomanip>
#include "constant.h"
#include "Name.h"

class Contact{
public:
    static const string DEFAULT_BUSINESS_PHONE;
    static const string DEFAULT_EMAIL;
    static const int DEFAULT_LOCATION;

    Contact();
    Contact(const string& first_name, const string& last_name, const string& business_phone, const string& email,const int& loaction);
    virtual ~Contact();

    friend bool operator==(const Contact& RHS, const Contact& LHS);
    friend bool operator!=(const Contact& RHS, const Contact& LHS);
    friend bool operator<(const Contact& RHS, const Contact& LHS);
    friend bool operator<=(const Contact& RHS, const Contact& LHS);
    friend bool operator>(const Contact& RHS, const Contact& LHS);
    friend bool operator>=(const Contact& RHS, const Contact& LHS);
    Contact& operator++();
    Contact& operator--();
    friend ostream& operator<<(std::ostream& outs, const Contact& show_me);
    
    virtual void ShowContact();

    Name get_name() const;
    string get_busubess_phone() const;
    string get_email() const;
    int get_location() const;
    void set_name(const Name& new_name);
    void set_busubess_phone(const string& new_phone_number);
    void set_email(const string& new_email);
    void set_location(int new_location);

    void set_next(Contact* new_contact);
    void set_previous(Contact* new_contact);
    Contact* get_next();
    Contact* get_previous();

protected:
    Name name;
    string business_phone;
    string email;
    int location;

private:
    Contact* next;
    Contact* previous;
};

const string Contact::DEFAULT_BUSINESS_PHONE = "1-408-222-8888";
const string Contact::DEFAULT_EMAIL = "jamesw@tpcommunications.com";
const int Contact::DEFAULT_LOCATION = 0;

Contact::Contact(){
    this->name = Name();
    this->business_phone = DEFAULT_BUSINESS_PHONE;
    this->email = DEFAULT_EMAIL;
    this->location = DEFAULT_LOCATION;
    this->next = nullptr;
    this->previous = nullptr;
};


Contact::Contact(const string& first_name, const string& last_name, const string& business_phone, const string& email,const int& loaction){
    this->name = Name(first_name, last_name);
    this->business_phone = business_phone;
    this->email = email;
    this->location = loaction;
    this->next = nullptr;
    this->previous = nullptr;
};


Contact::~Contact(){
    if (g_debug == true){
        cout << name << "has gone home ..."<< endl;
    }
    // next = nullptr;
    // previous = nullptr;
};


bool operator==(const Contact& RHS, const Contact& LHS){
    return (RHS.name == LHS.name);
};

bool operator!=(const Contact& RHS, const Contact& LHS){
    return !(RHS.name == LHS.name);
};

bool operator<(const Contact& RHS, const Contact& LHS){
    return (RHS.name < LHS.name);

};

bool operator<=(const Contact& RHS, const Contact& LHS){
    return !(RHS.name > LHS.name);
};

bool operator>(const Contact& RHS, const Contact& LHS){
    return (RHS.name > LHS.name);
};

bool operator>=(const Contact& RHS, const Contact& LHS){
    return !(RHS.name < LHS.name);
};

Contact& Contact::operator++(){
    return *this->next;
};

Contact& Contact::operator--(){
    return *this->previous;
};

ostream& operator<<(std::ostream& outs, const Contact& show_me){
    outs << show_me.name << "   " << show_me.location << "   " << show_me.business_phone << "   " << show_me.email;
    return outs;
};

void Contact::ShowContact(){
    cout << *this <<endl;
};


Name Contact::get_name() const{
    return name;
};

string Contact::get_busubess_phone() const{
    return business_phone;
};

string Contact::get_email() const{
    return email;
};

int Contact::get_location() const{
    return location;
};

void Contact::set_name(const Name& new_name){
    this->name = new_name;
};

void Contact::set_busubess_phone(const string& new_phone_number){
    this->business_phone = new_phone_number;
};

void Contact::set_email(const string& new_email){
    this->email = new_email;
};

void Contact::set_location(int new_location){
    this->location = new_location; 
};

void Contact::set_next(Contact* new_contact){
    this->next = new_contact;
};

void Contact::set_previous(Contact* new_contact){
    this->previous = new_contact;
};

Contact* Contact::get_next(){
    return this->next;
};

Contact* Contact::get_previous(){
    return this->previous;
};

#endif