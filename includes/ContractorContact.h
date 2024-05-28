#ifndef CONTRACTORCONTACT_H
#define CONTRACTORCONTACT_H

#include "Contact.h"


class  ContractorContact : public  Contact  {
public:
    ContractorContact();
    ContractorContact(const string& company, const string& assignemnt, const string& first_name, const string& last_name, const string& business_phone, const string& email,const int& loaction);
    ~ContractorContact();

    virtual void ShowContact()const;

    string get_company() const;
    string get_assignment() const;
    void set_company();
    void set_assignment();
private:
    string company;
    string assignment;
};


#endif