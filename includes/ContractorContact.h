#ifndef CONTRACTORCONTACT_H
#define CONTRACTORCONTACT_H

#include "Contact.h"


class  ContractorContact: public Contact {
public:
    static const string DEFAULT_COMPANY;
    static const int DEFAULT_MONTH;

    ContractorContact();
    ContractorContact(const string& first_name, const string& last_name, const int months, const string& company, const int location, const string& bussiness_phone, const string& email);
    virtual ~ContractorContact();

    virtual void ShowContact()const;
    friend ostream& operator<<(std::ostream& outs, const ContractorContact& show_me);

    string get_company() const;
    int get_month() const;
    void set_company(const string& new_company);
    void set_month(const int new_months);
private:
    string company;
    int months;
};


const string ContractorContact::DEFAULT_COMPANY = "TK Consultings";
const int ContractorContact::DEFAULT_MONTH = 6;

ContractorContact::ContractorContact():Contact(){
    this->company = DEFAULT_COMPANY;
    this->months = DEFAULT_MONTH;
};
ContractorContact::ContractorContact(const string& first_name, const string& last_name, const int months, const string& company, const int location, const string& bussiness_phone, const string& email):Contact(first_name, last_name, business_phone, email, location){
    this->company = company;
    this->months = months;
};

ContractorContact::~ContractorContact(){
    if (g_debug == true){
        cout << name << "has gone home ..."<< endl;
    }
};

void ContractorContact::ShowContact()const{
    cout << *this << endl;
};

ostream& operator<<(std::ostream& outs, const ContractorContact& show_me){
    outs << setw(25) << show_me.company << setw(25) << show_me.months << setw(25) << show_me.name << setw(25) << show_me.location << setw(25) << show_me.business_phone << setw(25) << show_me.email << endl;
    return outs;
};

string ContractorContact::get_company() const{
    return company;
};

int ContractorContact::get_month() const{
    return months;
};

void ContractorContact::set_company(const string& new_company){
    this->company = new_company;
};
void ContractorContact::set_month(const int new_months){
    this->months = new_months;
};

#endif