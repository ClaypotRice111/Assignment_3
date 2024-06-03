
#ifndef NAME_H
#define NAME_H


#include <iostream> 
#include <string>
#include "constant.h"


using namespace std;


class Name{
public:
    // static data
    static const string DEFAULT_NAME;

    // 3 CTOR
    Name();
    Name(const string& first_name, const string& last_name);
    ~Name();

    // Iter
    friend bool operator==(const Name& left, const Name& right);

    // compare last name first. if last name equal then compare first name
    friend bool operator<(const Name& left, const Name& right);
    friend bool operator>(const Name& left, const Name& right);

    // ostream
    friend ostream& operator<<(std::ostream& outs, const Name& show_me);

private:
    string last_name;
    string first_name;
};

    const string Name::DEFAULT_NAME = "EMPTRY";

Name::Name(){
    this->first_name = DEFAULT_NAME;
    this->last_name = DEFAULT_NAME;
};

Name::Name(const string& first_name, const string& last_name){
    this->first_name = first_name;
    this->last_name = last_name;
};

Name::~Name(){
    if (g_prompts)
        cout << "Name Class has been deleted..." << endl;
};

bool operator==(const Name& left, const Name& right){
    if (left.first_name == right.first_name && left.last_name == right.last_name){
        return true;
    }
    return false;
};

bool operator<(const Name& left, const Name& right){
    if (left.last_name < right.last_name) 
        return true;
    if (left.last_name > right.last_name) 
        return false;
    return (left.first_name < right.first_name);
};

bool operator>(const Name& left, const Name& right){
    if (left.last_name > right.last_name) 
        return true;
    if (left.last_name < right.last_name) 
        return false;
    return (left.first_name > right.first_name);
};

ostream& operator<<(std::ostream& outs, const Name& show_me){
    outs <<  show_me.first_name << " " << show_me.last_name;
    return outs;
};



#endif