#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>


//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/AddressBook.h"


//------------------------------------------------------------------------------------------

using namespace std;

class OutputCapturer {
public:
    OutputCapturer() : old_buf(std::cout.rdbuf()), ss() {
        std::cout.rdbuf(ss.rdbuf());
    }
    ~OutputCapturer() {
        std::cout.rdbuf(old_buf);
    }
    std::string getOutput() const {
        return ss.str();
    }
private:
    std::stringstream ss;
    std::streambuf* old_buf;
};


TEST(NameTest, DefaultConstructor) {
    Name n;
    EXPECT_EQ(n, Name(Name::DEFAULT_NAME, Name::DEFAULT_NAME));
}

TEST(NameTest, ParameterizedConstructor) {
    Name n("John", "Doe");
    EXPECT_EQ(n, Name("John", "Doe"));
}

TEST(NameTest, EqualityOperator) {
    Name n1("Jane", "Doe");
    Name n2("Jane", "Doe");
    EXPECT_EQ(n1, n2);
}

TEST(NameTest, LessThanOperator) {
    Name n1("Alice", "Smith");
    Name n2("Bob", "Smith");
    Name n3("Alice", "Brown");
    EXPECT_LT(n3, n1);
    EXPECT_LT(n1, n2);
}

TEST(NameTest, GreaterThanOperator) {
    Name n1("Alice", "Smith");
    Name n2("Bob", "Smith");
    Name n3("Alice", "Brown");
    EXPECT_GT(n1, n3);
    EXPECT_GT(n2, n1);
}

TEST(NameTest, OstreamOperator) {
    Name n("John", "Doe");
    std::stringstream ss;
    ss << n;
    EXPECT_EQ(ss.str(), "John Doe");
}

// Test the default constructor
TEST(ContactTest, DefaultConstructor) {
    Contact c;
    EXPECT_EQ(c.get_name(), Name(Name::DEFAULT_NAME, Name::DEFAULT_NAME));
    EXPECT_EQ(c.get_business_phone(), Contact::DEFAULT_BUSINESS_PHONE);
    EXPECT_EQ(c.get_email(), Contact::DEFAULT_EMAIL);
    EXPECT_EQ(c.get_location(), Contact::DEFAULT_LOCATION);
}

// Test the parameterized constructor
TEST(ContactTest, ParameterizedConstructor) {
    Contact c("John", "Doe", "123-456-7890", "john.doe@example.com", 1);
    EXPECT_EQ(c.get_name(), Name("John", "Doe"));
    EXPECT_EQ(c.get_business_phone(), "123-456-7890");
    EXPECT_EQ(c.get_email(), "john.doe@example.com");
    EXPECT_EQ(c.get_location(), 1);
}

// Test the equality operator
TEST(ContactTest, EqualityOperator) {
    Contact c1("Jane", "Doe", "123-456-7890", "jane.doe@example.com", 1);
    Contact c2("Jane", "Doe", "123-456-7890", "jane.doe@example.com", 1);
    EXPECT_EQ(c1, c2);
}

// Test the inequality operator
TEST(ContactTest, InequalityOperator) {
    Contact c1("Jane", "Doe", "123-456-7890", "jane.doe@example.com", 1);
    Contact c2("John", "Doe", "123-456-7890", "john.doe@example.com", 1);
    EXPECT_NE(c1, c2);
}

// Test the less than operator
TEST(ContactTest, LessThanOperator) {
    Contact c1("Alice", "Smith", "123-456-7890", "alice.smith@example.com", 1);
    Contact c2("Bob", "Smith", "123-456-7890", "bob.smith@example.com", 1);
    EXPECT_LT(c1, c2);
}

// Test the greater than operator
TEST(ContactTest, GreaterThanOperator) {
    Contact c1("Alice", "Smith", "123-456-7890", "alice.smith@example.com", 1);
    Contact c2("Bob", "Smith", "123-456-7890", "bob.smith@example.com", 1);
    EXPECT_GT(c2, c1);
}

// Test the ostream operator
TEST(ContactTest, OstreamOperator) {
    Contact c("John", "Doe", "123-456-7890", "john.doe@example.com", 1);
    std::stringstream ss;
    ss << c;
    EXPECT_EQ(ss.str(), "John Doe   1   123-456-7890   john.doe@example.com");
}

// Test the accessor and mutator methods
TEST(ContactTest, AccessorMutator) {
    Contact c;
    c.set_name(Name("John", "Doe"));
    c.set_business_phone("123-456-7890");
    c.set_email("john.doe@example.com");
    c.set_location(1);

    EXPECT_EQ(c.get_name(), Name("John", "Doe"));
    EXPECT_EQ(c.get_business_phone(), "123-456-7890");
    EXPECT_EQ(c.get_email(), "john.doe@example.com");
    EXPECT_EQ(c.get_location(), 1);
}


// Test the default constructor
TEST(ContractorContactTest, DefaultConstructor) {
    ContractorContact cc;
    EXPECT_EQ(cc.get_name(), Name(Name::DEFAULT_NAME, Name::DEFAULT_NAME));
    EXPECT_EQ(cc.get_business_phone(), Contact::DEFAULT_BUSINESS_PHONE);
    EXPECT_EQ(cc.get_email(), Contact::DEFAULT_EMAIL);
    EXPECT_EQ(cc.get_location(), Contact::DEFAULT_LOCATION);
    EXPECT_EQ(cc.get_company(), ContractorContact::DEFAULT_COMPANY);
    EXPECT_EQ(cc.get_month(), ContractorContact::DEFAULT_MONTH);
}

// Test the parameterized constructor
TEST(ContractorContactTest, ParameterizedConstructor) {
    ContractorContact cc("John", "Doe", 12, "TechCorp", 1, "123-456-7890", "john.doe@example.com");
    EXPECT_EQ(cc.get_name(), Name("John", "Doe"));
    EXPECT_EQ(cc.get_business_phone(), "123-456-7890");
    EXPECT_EQ(cc.get_email(), "john.doe@example.com");
    EXPECT_EQ(cc.get_location(), 1);
    EXPECT_EQ(cc.get_company(), "TechCorp");
    EXPECT_EQ(cc.get_month(), 12);
}

// Test the ShowContact method
TEST(ContractorContactTest, ShowContact) {
    ContractorContact cc("John", "Doe", 12, "TechCorp", 1, "123-456-7890", "john.doe@example.com");
    OutputCapturer capturer;
    cc.ShowContact();
    std::string output = capturer.getOutput();
    EXPECT_EQ(output, "John Doe    TechCorp    12 months (contractor)     Room 1    123-456-7890    john.doe@example.com\n");
}

// Test the accessor and mutator methods
TEST(ContractorContactTest, AccessorMutator) {
    ContractorContact cc;
    cc.set_name(Name("John", "Doe"));
    cc.set_business_phone("123-456-7890");
    cc.set_email("john.doe@example.com");
    cc.set_location(1);
    cc.set_company("TechCorp");
    cc.set_month(12);

    EXPECT_EQ(cc.get_name(), Name("John", "Doe"));
    EXPECT_EQ(cc.get_business_phone(), "123-456-7890");
    EXPECT_EQ(cc.get_email(), "john.doe@example.com");
    EXPECT_EQ(cc.get_location(), 1);
    EXPECT_EQ(cc.get_company(), "TechCorp");
    EXPECT_EQ(cc.get_month(), 12);
}


// Test the default constructor
TEST(EmployeeContactTest, DefaultConstructor) {
    EmployeeContact ec;
    EXPECT_EQ(ec.get_name(), Name(Name::DEFAULT_NAME, Name::DEFAULT_NAME));
    EXPECT_EQ(ec.get_business_phone(), Contact::DEFAULT_BUSINESS_PHONE);
    EXPECT_EQ(ec.get_email(), Contact::DEFAULT_EMAIL);
    EXPECT_EQ(ec.get_location(), Contact::DEFAULT_LOCATION);
    EXPECT_EQ(ec.get_title(), EmployeeContact::DEFAULT_TITLE);
    EXPECT_EQ(ec.get_department(), EmployeeContact::DEFAULT_DEPARTMENT);
}

// Test the parameterized constructor
TEST(EmployeeContactTest, ParameterizedConstructor) {
    EmployeeContact ec("John", "Doe", "123-456-7890", "john.doe@example.com", 1, "Manager", "HR");
    EXPECT_EQ(ec.get_name(), Name("John", "Doe"));
    EXPECT_EQ(ec.get_business_phone(), "123-456-7890");
    EXPECT_EQ(ec.get_email(), "john.doe@example.com");
    EXPECT_EQ(ec.get_location(), 1);
    EXPECT_EQ(ec.get_title(), "Manager");
    EXPECT_EQ(ec.get_department(), "HR");
}

// Test the ShowContact method
TEST(EmployeeContactTest, ShowContact) {
    EmployeeContact ec("John", "Doe", "123-456-7890", "john.doe@example.com", 1, "Manager", "HR");
    OutputCapturer capturer;
    ec.ShowContact();
    std::string output = capturer.getOutput();
    EXPECT_EQ(output, "John Doe    Manager    HR     Room1    123-456-7890    john.doe@example.com\n");
}

// Test the accessor and mutator methods
TEST(EmployeeContactTest, AccessorMutator) {
    EmployeeContact ec;
    ec.set_name(Name("John", "Doe"));
    ec.set_business_phone("123-456-7890");
    ec.set_email("john.doe@example.com");
    ec.set_location(1);
    ec.set_title("Manager");
    ec.set_department("HR");

    EXPECT_EQ(ec.get_name(), Name("John", "Doe"));
    EXPECT_EQ(ec.get_business_phone(), "123-456-7890");
    EXPECT_EQ(ec.get_email(), "john.doe@example.com");
    EXPECT_EQ(ec.get_location(), 1);
    EXPECT_EQ(ec.get_title(), "Manager");
    EXPECT_EQ(ec.get_department(), "HR");
}


// Test the initialization of the ContactList
TEST(ContactListTest, Initialization) {
    ContactList cl;
    EXPECT_EQ(cl.get_list(), nullptr);
}

// Test inserting contacts and ensuring the order is correct
TEST(ContactListTest, InsertAndOrder) {
    ContactList cl;
    Contact* contact1 = new EmployeeContact("Alice", "Smith", "123-456-7890", "alice.smith@example.com", 1, "Manager", "HR");
    Contact* contact2 = new ContractorContact("Bob", "Brown", 6, "TechCorp", 2, "234-567-8901", "bob.brown@example.com");
    Contact* contact3 = new EmployeeContact("Carol", "Jones", "345-678-9012", "carol.jones@example.com", 3, "Developer", "IT");

    cl.Insert(contact2);
    cl.Insert(contact1);
    cl.Insert(contact3);

    //cl.ShowAllContacts();

    Contact* current = cl.get_list();
    EXPECT_EQ(current->get_name(), Name("Bob", "Brown"));
    current = current->get_next();
    EXPECT_EQ(current->get_name(), Name("Carol", "Jones"));
    current = current->get_next();
    EXPECT_EQ(current->get_name(), Name("Alice", "Smith"));
}

// Test searching by name
TEST(ContactListTest, SearchByName) {
    ContactList cl;
    Contact* contact1 = new EmployeeContact("Alice", "Smith", "123-456-7890", "alice.smith@example.com", 1, "Manager", "HR");
    Contact* contact2 = new ContractorContact("Bob", "Brown", 6, "TechCorp", 2, "234-567-8901", "bob.brown@example.com");
    cl.Insert(contact1);
    cl.Insert(contact2);

    std::stringstream ss;
    OutputCapturer capturer;

    cl.SearchByName(Name("Bob", "Brown"));
    std::string output = capturer.getOutput();
    EXPECT_EQ(output, "Bob Brown    TechCorp    6 months (contractor)     Room 2    234-567-8901    bob.brown@example.com\n");
}

// Test searching by department
TEST(ContactListTest, SearchByDepartment) {
    ContactList cl;
    Contact* contact1 = new EmployeeContact("Alice", "Smith", "123-456-7890", "alice.smith@example.com", 1, "Manager", "HR");
    Contact* contact2 = new EmployeeContact("Carol", "Jones", "345-678-9012", "carol.jones@example.com", 3, "Developer", "IT");
    cl.Insert(contact1);
    cl.Insert(contact2);

    std::stringstream ss;
    OutputCapturer capturer;

    cl.SearchByDepartment("HR");
    std::string output = capturer.getOutput();
    EXPECT_EQ(output, "Alice Smith    Manager    HR     Room1    123-456-7890    alice.smith@example.com\n");
}

// Test clearing the list
TEST(ContactListTest, ClearList) {
    ContactList cl;
    Contact* contact1 = new EmployeeContact("Alice", "Smith", "123-456-7890", "alice.smith@example.com", 1, "Manager", "HR");
    cl.Insert(contact1);
    cl.Clear();
    EXPECT_EQ(cl.get_list(), nullptr);
}

TEST(ContactListTest, RemoveExistingContact) {
    ContactList contactList;
    // Populate the contact list with some contacts
    contactList.Insert(new EmployeeContact("John", "Doe", "123-456-7890", "john.doe@example.com", 1, "Manager", "HR"));
    contactList.Insert(new EmployeeContact("Alice", "Smith", "234-567-8901", "alice.smith@example.com", 2, "Engineer", "IT"));

    Name targetName("John", "Doe");
    Contact* removedContact = contactList.RemoveContact(targetName);
    
    EXPECT_NE(removedContact, nullptr); // Check if a contact was removed
    EXPECT_EQ(removedContact->get_name(), targetName); // Check if the correct contact was removed
    delete removedContact; // Deallocate memory for the removed contact
}

// Test removing a contact that does not exist in the list
TEST(ContactListTest, RemoveNonExistingContact) {
    ContactList contactList;
    // Populate the contact list with some contacts
    contactList.Insert(new EmployeeContact("John", "Doe", "123-456-7890", "john.doe@example.com", 1, "Manager", "HR"));
    contactList.Insert(new EmployeeContact("Alice", "Smith", "234-567-8901", "alice.smith@example.com", 2, "Engineer", "IT"));

    Name targetName("Bob", "Brown"); // A contact that does not exist in the list
    Contact* removedContact = contactList.RemoveContact(targetName);

    EXPECT_EQ(removedContact, nullptr); // Check if nullptr is returned (contact not found)
}

// Test if the method returns the correct pointer to the removed contact
TEST(ContactListTest, CorrectPointerReturned) {
    ContactList contactList;
    // Populate the contact list with some contacts
    contactList.Insert(new EmployeeContact("John", "Doe", "123-456-7890", "john.doe@example.com", 1, "Manager", "HR"));
    contactList.Insert(new EmployeeContact("Alice", "Smith", "234-567-8901", "alice.smith@example.com", 2, "Engineer", "IT"));

    Name targetName("John", "Doe");
    Contact* removedContact = contactList.RemoveContact(targetName);

    // Check if the pointer returned points to the correct contact
    EXPECT_EQ(removedContact->get_name(), targetName);
    delete removedContact; // Deallocate memory for the removed contact
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

