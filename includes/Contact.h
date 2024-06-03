#ifndef CONTACR
#define CONTACR

#include <iostream>
#include <string>
#include <iomanip>
#include "Name.h"

class Contact{
public:
    //static datas
    static const string DEFAULT_BUSINESS_PHONE;
    static const string DEFAULT_EMAIL;
    static const int DEFAULT_LOCATION;

    // 3 COTR
    Contact();
    Contact(const string& first_name, const string& last_name, const string& business_phone, const string& email,const int& loaction);
    virtual ~Contact();

    // operator functions
    friend bool operator==(const Contact& left, const Contact& right);
    friend bool operator!=(const Contact& left, const Contact& right);
    friend bool operator<(const Contact& left, const Contact& right);
    friend bool operator<=(const Contact& left, const Contact& right);
    friend bool operator>(const Contact& left, const Contact& right);
    friend bool operator>=(const Contact& left, const Contact& right);

    // print functions
    friend ostream& operator<<(std::ostream& outs, const Contact& show_me);
    virtual void ShowContact() const;

    // access functions
    Name get_name() const;
    string get_business_phone() const;
    string get_email() const;
    int get_location() const;
    void set_name(const Name& new_name);
    void set_business_phone(const string& new_phone_number);
    void set_email(const string& new_email);
    void set_location(int new_location);

    void set_next(Contact* new_contact);
    Contact* get_next();


protected:
    Name name;
    string business_phone;
    string email;
    int location;

private:
    Contact* next;
};

const string Contact::DEFAULT_BUSINESS_PHONE = "1-408-222-8888";
const string Contact::DEFAULT_EMAIL = "jamesw@tpcommunications.com";
const int Contact::DEFAULT_LOCATION = 0;

Contact::Contact(){
    this->business_phone = DEFAULT_BUSINESS_PHONE;
    this->email = DEFAULT_EMAIL;
    this->location = DEFAULT_LOCATION;
    this->next = nullptr;
};


Contact::Contact(const string& first_name, const string& last_name, const string& business_phone, const string& email,const int& loaction){
    this->name = Name(first_name, last_name);
    this->business_phone = business_phone;
    this->email = email;
    this->location = loaction;
    this->next = nullptr;
};


Contact::~Contact(){
    if (g_prompts)
        cout << name << "has gone home ..."<< endl;

};


bool operator==(const Contact& left, const Contact& right){
    return (left.name == right.name);
};

bool operator!=(const Contact& left, const Contact& right){
    return !(left.name == right.name);
};

bool operator<(const Contact& left, const Contact& right){
    return (left.name < right.name);

};

bool operator<=(const Contact& left, const Contact& right){
    return !(left.name > right.name);
};

bool operator>(const Contact& left, const Contact& right){
    return (left.name > right.name);
};

bool operator>=(const Contact& left, const Contact& right){
    return !(left.name < right.name);
};

ostream& operator<<(std::ostream& outs, const Contact& show_me){
    outs << show_me.name << "   " << show_me.location << "   " << show_me.business_phone << "   " << show_me.email;
    return outs;
};

void Contact::ShowContact() const{
    cout << name << "   " << location << "   " << business_phone << "   " << email << endl;
};


Name Contact::get_name() const{
    return name;
};

string Contact::get_business_phone() const{
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

void Contact::set_business_phone(const string& new_phone_number){
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

Contact* Contact::get_next(){
    return this->next;
};


#endif