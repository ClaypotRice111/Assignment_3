#ifndef CONTACR
#define CONTACR

#include <iostream>
#include <string>
#include "constant.h"
#include "Name.h"

class Contact{
    static const string DEFAULT_BUSINESS_PHONE;
    static const string DEFAULT_EMAIL;
    static const int DEFAULT_LOCATION;

    Contact();
    Contact(const string& first_name, const string& last_name, const string& business_phone, const string& email,const int& loaction);
    ~Contact();

    
    virtual void ShowContact();


    Name get_name();
    string get_busubess_phone();
    string get_email();
    string get_location();
    Name set_name();
    string set_busubess_phone();
    string set_email();
    string set_location();


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
    this->name = Name();
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
    if (g_debug == true){
        cout << "Contact Class havs been deleted..." << endl;
    }
    delete next;
};



#endif