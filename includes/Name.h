
#ifndef NAME_H
#define NAME_H


//  class Name: simple class containing last name and first name as member data. This class must overload
//  the equality operator == to compare two Name objects: name_1 == name_2 return true if both Name objects 
//  have the same first name and last name. The comparison must be case sensitive (james West is NOT the 
//  same as James wesT). If the names are not the same return false. To display a Name object you have 
//  two choices: provide getters for first name and last name or overload the operator <<. You know which 
//  one is my preference. It's up to you to decide if you want to go to the next level or stay with what 
//  everyone currently taking CS 2A in Winter 2023 knows :-)

#include <iostream> 
#include <string>
#include "constant.h"


using namespace std;




class Name{
public:
    //Name();
    Name(const string& first_name = "None", const string& last_name = "None");
    ~Name();

    friend bool operator==(const Name& RHS, const Name& LHS);
    // friend bool operator!=(const Name& RHS, const Name& LHS);
    friend bool operator<(const Name& RHS, const Name& LHS);
    // friend bool operator<=(const Name& RHS, const Name& LHS);
    friend bool operator>(const Name& RHS, const Name& LHS);
    // friend bool operator>=(const Name& RHS, const Name& LHS);
    friend ostream& operator<<(std::ostream& outs, const Name& show_me);

private:
    string last_name;
    string first_name;
};


// Name::Name(){
//     this->first_name = "";
//     this->last_name = "";
// };

Name::Name(const string& first_name, const string& last_name){
    this->first_name = first_name;
    this->last_name = last_name;
};

Name::~Name(){
    if (g_debug == true){
        cout << "Name Class has been deleted..." << endl;
    }
};

bool operator==(const Name& RHS, const Name& LHS){
    if (RHS.first_name == LHS.first_name && RHS.last_name == LHS.last_name){
        return true;
    }
    return false;
};

bool operator<(const Name& RHS, const Name& LHS){
    if (RHS.first_name < LHS.first_name){
        return true;
    }else if(RHS.first_name == LHS.first_name){
        if(RHS.last_name < LHS.last_name){
            return true;
        }
    }
    return false;
};

bool operator>(const Name& RHS, const Name& LHS){
    if (RHS.first_name > LHS.first_name){
        return true;
    }else if(RHS.first_name == LHS.first_name){
        if(RHS.last_name > LHS.last_name){
            return true;
        }
    }
    return false;
};

ostream& operator<<(std::ostream& outs, const Name& show_me){
    outs <<  show_me.first_name << " " << show_me.last_name;
    return outs;
};



#endif