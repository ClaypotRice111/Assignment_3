#ifndef CONTACT_H
#define CONTACT_H

#include "ContractorContact.h"
#include "EmployeeContact.h"


class ContactList {
public:
    ContactList();
    ~ContactList();

    void Init();
    void ShowAllContacts() const;
    void SearchByName(const Name& target_name) const;
    void SearchByDepartment(const string& department) const;

    // ContactList operator=(const ContactList& other);
    // Contact& operator[](int index);
    // Contact& operator++();
    // Contact& operator++(int);
    // friend ostream& operator<<(std::ostream& outs, const ContactList& show_me);

    // for testing 
    Contact* get_list(); 
    void Insert(Contact* newContact);
    Contact* FindContact(const Name& target) const;
    void ClearList();

private:
    // Contact* FindContact(const Name& target) const;
    // void Insert(Contact* newContact);
    void InsertSort(Contact* newContact);
    void DeleteNode(Contact* target);
    //void ClearList();

    // Contact* begin();
    // Contact* end();

    Contact* head;
};



ContactList::ContactList(){
    head = nullptr;
};

ContactList::~ContactList(){
    if (g_debug == true){
        cout << "contact list has been deleted" << endl;
    }
    ClearList();
};

void ContactList::Init(){
    Insert ( new EmployeeContact ("Alice", "Johnson", "1-408-790-1234", "alicej@tpcommuniations", 25, "Marketing Manager", "Marketing"));
    Insert ( new EmployeeContact ("Bob", "Smith", "1-408-790-5678", "bobs@tpcommuniations", 30, "Sales Executive", "Sales"));
    Insert ( new EmployeeContact ("Charlie", "Brown", "1-408-790-9876", "charlieb@tpcommuniations", 28, "Financial Analyst", "Finance"));
    Insert ( new EmployeeContact ("Diana", "Prince", "1-408-790-4321", "dianap@tpcommuniations", 35, "Product Manager", "Product"));
    Insert ( new EmployeeContact ("Eve", "Adams", "1-408-790-8765", "evea@tpcommuniations", 22, "Graphic Designer", "Design"));
    Insert ( new EmployeeContact ("Frank", "Miller", "1-408-790-3456", "frankm@tpcommuniations", 27, "Operations Manager", "Operations"));
    Insert ( new EmployeeContact ("Grace", "Hopper", "1-408-790-6543", "graceh@tpcommuniations", 33, "Software Developer", "Engineering"));
    Insert ( new EmployeeContact ("Hank", "Pym", "1-408-790-7890", "hankp@tpcommuniations", 26, "Chemist", "Research"));
    Insert ( new EmployeeContact ("Ivy", "Green", "1-408-790-3210", "ivyg@tpcommuniations", 31, "HR Manager", "Human Resources"));
    Insert ( new EmployeeContact ("Jack", "Daniels", "1-408-790-6540", "jackd@tpcommuniations", 29, "Business Analyst", "Business"));
    Insert ( new EmployeeContact ("Karen", "Smith", "1-408-790-2345", "karens@tpcommuniations", 24, "Content Writer", "Marketing"));
    Insert ( new EmployeeContact ("Leo", "Nardo", "1-408-790-5432", "leon@tpcommuniations", 36, "UX Designer", "Design"));
    Insert ( new EmployeeContact ("Mona", "Lisa", "1-408-790-7654", "monal@tpcommuniations", 32, "Data Scientist", "Data"));
    Insert ( new EmployeeContact ("Nina", "Simone", "1-408-790-8764", "ninas@tpcommuniations", 28, "Accountant", "Finance"));
    Insert ( new EmployeeContact ("Oscar", "Wilde", "1-408-790-0987", "oscarw@tpcommuniations", 34, "Legal Advisor", "Legal"));
    Insert ( new EmployeeContact ("Pamela", "Anderson", "1-408-790-7653", "pamelaa@tpcommuniations", 27, "Recruiter", "Human Resources"));
    Insert ( new EmployeeContact ("Quincy", "Jones", "1-408-790-1230", "quincyj@tpcommuniations", 29, "Project Manager", "Operations"));
    Insert ( new EmployeeContact ("Rachel", "Green", "1-408-790-3211", "rachelg@tpcommuniations", 25, "Sales Representative", "Sales"));
    Insert ( new EmployeeContact ("Steve", "Jobs", "1-408-790-4567", "stevej@tpcommuniations", 37, "Chief Executive Officer", "Executive"));
    Insert ( new EmployeeContact ("Tina", "Turner", "1-408-790-7891", "tinat@tpcommuniations", 31, "Support Specialist", "Customer Support"));
    Insert ( new EmployeeContact ("Uma", "Thurman", "1-408-790-2341", "umat@tpcommuniations", 26, "Quality Assurance", "Engineering"));
    Insert ( new EmployeeContact ("Victor", "Hugo", "1-408-790-6789", "victorh@tpcommuniations", 35, "Network Engineer", "IT"));
    Insert ( new EmployeeContact ("Wanda", "Maximoff", "1-408-790-9875", "wandam@tpcommuniations", 30, "Security Analyst", "IT"));
    Insert ( new EmployeeContact ("Xander", "Cage", "1-408-790-4320", "xanderc@tpcommuniations", 28, "Technical Writer", "Documentation"));
    Insert ( new EmployeeContact ("Yvonne", "Strahovski", "1-408-790-8763", "yvonnes@tpcommuniations", 27, "Digital Marketer", "Marketing"));
    Insert ( new EmployeeContact ("Zack", "Morris", "1-408-790-5431", "zackm@tpcommuniations", 29, "Customer Service Rep", "Customer Support"));
    Insert ( new ContractorContact ("John", "Doe", 5, "ABC Corp", 7, "1-408-790-1234", "johnd@tpcommunications.com"));
    Insert ( new ContractorContact ("Jane", "Smith", 8, "XYZ Solutions", 12, "1-408-790-5678", "janes@tpcommunications.com"));
    Insert ( new ContractorContact ("Michael", "Johnson", 10, "Tech Innovators", 15, "1-408-790-9101", "michaelj@tpcommunications.com"));
    Insert ( new ContractorContact ("Emily", "Davis", 4, "Creative Consultancy", 6, "1-408-790-1123", "emilyd@tpcommunications.com"));
    Insert ( new ContractorContact ("David", "Brown", 9, "Strategic Advisors", 14, "1-408-790-1456", "davidb@tpcommunications.com"));
    Insert ( new ContractorContact ("Sarah", "Wilson", 7, "Solution Seekers", 11, "1-408-790-1789", "sarahw@tpcommunications.com"));
    Insert ( new ContractorContact ("Chris", "Martinez", 6, "Innovative Minds", 10, "1-408-790-2101", "chrism@tpcommunications.com"));
    Insert ( new ContractorContact ("Anna", "Garcia", 8, "Advanced Insights", 13, "1-408-790-2345", "annag@tpcommunications.com"));
    Insert ( new ContractorContact ("Brian", "Clark", 5, "Future Consultants", 7, "1-408-790-2678", "brianc@tpcommunications.com"));
    Insert ( new ContractorContact ("Jessica", "Rodriguez", 9, "Elite Solutions", 12, "1-408-790-2901", "jessicar@tpcommunications.com"));
    Insert ( new ContractorContact ("Kevin", "Lewis", 10, "Prime Consults", 15, "1-408-790-3123", "kevinl@tpcommunications.com"));
    Insert ( new ContractorContact ("Laura", "Walker", 6, "Trusted Partners", 9, "1-408-790-3456", "lauraw@tpcommunications.com"));
    Insert ( new ContractorContact ("Daniel", "Hall", 7, "Optimal Strategies", 11, "1-408-790-3789", "danielh@tpcommunications.com"));
    Insert ( new ContractorContact ("Rachel", "Allen", 8, "Superior Consultants", 13, "1-408-790-4101", "rachela@tpcommunications.com"));
    Insert ( new ContractorContact ("Matthew", "Young", 5, "Insight Experts", 6, "1-408-790-4345", "matthewy@tpcommunications.com"));
    Insert ( new ContractorContact ("Sophia", "Hernandez", 9, "Tech Visionaries", 14, "1-408-790-4678", "sophiah@tpcommunications.com"));
    Insert ( new ContractorContact ("Joshua", "King", 10, "Bright Futures", 15, "1-408-790-4901", "joshuak@tpcommunications.com"));
    Insert ( new ContractorContact ("Megan", "Scott", 6, "Pro Consults", 9, "1-408-790-5123", "megans@tpcommunications.com"));
    Insert ( new ContractorContact ("Nathan", "Green", 7, "NextGen Advisors", 11, "1-408-790-5456", "nathang@tpcommunications.com"));
    Insert ( new ContractorContact ("Olivia", "Adams", 8, "Advanced Tech", 13, "1-408-790-5789", "oliviaa@tpcommunications.com"));
};

void ContactList::ShowAllContacts() const{
    Contact* p_node = head;
    while (p_node){
        p_node->ShowContact();
        p_node = p_node->get_next();
    }
};

void ContactList::SearchByName(const Name& target_name) const{
    Contact* p_contact = FindContact(target_name);
    if (p_contact){
        p_contact->ShowContact();
    }else{
        cout << "person not found" << endl;
    }

}; 

void ContactList::SearchByDepartment(const string& department) const{
    Contact* p_current = head;
    EmployeeContact* p_empmployee_contact;
    while (p_current) {
        EmployeeContact* p_empmployee_contact = dynamic_cast<EmployeeContact*>(p_current);
        if (p_empmployee_contact && p_empmployee_contact->get_department() == department) {
            p_empmployee_contact->ShowContact();
        }
        p_current = p_current->get_next();
    }
};

Contact* ContactList::get_list(){
    return head;
}

Contact* ContactList::FindContact(const Name& target) const{
    if (!head){
        return nullptr;
    }
    Contact* p_node = head;
    while(p_node){

        if (target < p_node->get_name()){
            return nullptr;
        }
        if (target == p_node->get_name()){
            return p_node;
        }
        p_node = p_node->get_next();
    }
    return nullptr;
};

void ContactList::Insert(Contact* newContact){
    return InsertSort(newContact);
};

void ContactList::InsertSort(Contact* newContact){
    if (!head){// case 1: head node is null pointer
        head = newContact;
    }else if(head > newContact){// case 2: insert a head
        newContact->set_next(head);
        head->set_previous(newContact);
        head = newContact;
    }else{//case 3: insert after (pre-check)
        Contact* p_current = head;
        while (p_current->get_next() && p_current->get_next() <= newContact) {
            p_current = p_current->get_next();
        }
        // Now p_current points to the last node whose name is less than or equal to newContact's name
        Contact* p_next = p_current->get_next();
        p_current->set_next(newContact);
        newContact->set_previous(p_current);
        if (p_next) {
            p_next->set_previous(newContact);
            newContact->set_next(p_next);
        }
    }
};



void DeleteNode(Contact* target){
    Contact* p_previous = target->get_previous();
    Contact* p_next = target->get_next();

    p_previous->set_next(p_next);
    p_next->set_previous(p_previous);
    delete target;
};

void ContactList::ClearList(){
    Contact* p_current = head;
    Contact* p_next;
    while (p_current){
        p_next = p_current->get_next();
        delete p_current;
        p_current = p_next;
    }
    head = nullptr;
};



#endif