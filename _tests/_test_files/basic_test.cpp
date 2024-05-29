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
// name class


TEST(NameTest, EqualityOperator) {
    Name name1("John", "Doe");
    Name name2("John", "Doe");
    Name name3("Jane", "Doe");

    EXPECT_TRUE(name1 == name2);
    EXPECT_FALSE(name1 == name3);
}

TEST(NameTest, LessThanOperator) {
    Name name1("John", "Doe");
    Name name2("Jane", "Doe");
    Name name3("John", "Smith");

    EXPECT_TRUE(name2 < name1);
    EXPECT_FALSE(name1 < name2);
    EXPECT_TRUE(name1 < name3);
}

TEST(NameTest, GreaterThanOperator) {
    Name name1("John", "Doe");
    Name name2("Jane", "Doe");
    Name name3("John", "Smith");

    EXPECT_TRUE(name1 > name2);
    EXPECT_FALSE(name2 > name1);
    EXPECT_FALSE(name1 > name3);
}

TEST(NameTest, StreamOperator) {
    Name name("John", "Doe");
    std::ostringstream oss;
    oss << name;
    EXPECT_EQ(oss.str(), "John Doe");
}



// contact class


TEST(ContactTest, DefaultConstructor) {
    Contact contact;
    EXPECT_EQ(contact.get_name(), Name());
    EXPECT_EQ(contact.get_busubess_phone(), Contact::DEFAULT_BUSINESS_PHONE);
    EXPECT_EQ(contact.get_email(), Contact::DEFAULT_EMAIL);
    EXPECT_EQ(contact.get_location(), Contact::DEFAULT_LOCATION);
}

TEST(ContactTest, ParameterizedConstructor) {
    Contact contact("John", "Doe", "123-456-7890", "john.doe@example.com", 42);
    EXPECT_EQ(contact.get_name(), Name("John", "Doe"));
    EXPECT_EQ(contact.get_busubess_phone(), "123-456-7890");
    EXPECT_EQ(contact.get_email(), "john.doe@example.com");
    EXPECT_EQ(contact.get_location(), 42);
}

TEST(ContactTest, SettersAndGetters) {
    Contact contact;
    contact.set_name(Name("Jane", "Smith"));
    contact.set_busubess_phone("987-654-3210");
    contact.set_email("jane.smith@example.com");
    contact.set_location(24);

    EXPECT_EQ(contact.get_name(), Name("Jane", "Smith"));
    EXPECT_EQ(contact.get_busubess_phone(), "987-654-3210");
    EXPECT_EQ(contact.get_email(), "jane.smith@example.com");
    EXPECT_EQ(contact.get_location(), 24);
}

TEST(ContactTest, ComparisonOperators) {
    Contact contact1("Alice", "Wonderland", "111-222-3333", "alice@example.com", 1);
    Contact contact2("Bob", "Builder", "222-333-4444", "bob@example.com", 2);

    EXPECT_FALSE(contact1 == contact2);
    EXPECT_TRUE(contact1 != contact2);
    EXPECT_TRUE(contact1 < contact2);
    EXPECT_TRUE(contact1 <= contact2);
    EXPECT_FALSE(contact1 > contact2);
    EXPECT_FALSE(contact1 >= contact2);

    Contact contact3("Alice", "Wonderland", "111-222-3333", "alice@example.com", 1);
    EXPECT_TRUE(contact1 == contact3);
    EXPECT_FALSE(contact1 != contact3);
    EXPECT_FALSE(contact1 < contact3);
    EXPECT_TRUE(contact1 <= contact3);
    EXPECT_FALSE(contact1 > contact3);
    EXPECT_TRUE(contact1 >= contact3);
}

TEST(ContactTest, IncrementDecrementOperators) {
    Contact contact1("Alice", "Wonderland", "111-222-3333", "alice@example.com", 1);
    Contact contact2("Bob", "Builder", "222-333-4444", "bob@example.com", 2);

    contact1.set_next(&contact2);
    contact2.set_previous(&contact1);

    EXPECT_EQ(++contact1, contact2);
    EXPECT_EQ(--contact2, contact1);
}

TEST(ContactTest, StreamOperator) {
    Contact contact("Alice", "Wonderland", "111-222-3333", "alice@example.com", 1);
    std::ostringstream oss;
    oss << contact;
    EXPECT_EQ(oss.str(), "Alice Wonderland   1   111-222-3333   alice@example.com");
}

TEST(ContactTest, ShowContact) {
    Contact contact("Alice", "Wonderland", "111-222-3333", "alice@example.com", 1);
    std::ostringstream oss;
    std::streambuf* coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(oss.rdbuf()); //redirect std::cout to oss
    contact.ShowContact();
    std::cout.rdbuf(coutbuf); //reset to standard output
    EXPECT_EQ(oss.str(), "Alice Wonderland   1   111-222-3333   alice@example.com\n");
}

// employeecontact class

TEST(EmployeeContactTest, DefaultConstructor) {
    EmployeeContact contact;

    EXPECT_EQ(contact.get_title(), EmployeeContact::DEFAULT_TITLE);
    EXPECT_EQ(contact.get_department(), EmployeeContact::DEFAULT_DEPARTMENT);
}

TEST(EmployeeContactTest, ParameterizedConstructor) {
    std::string first_name = "John";
    std::string last_name = "Doe";
    std::string business_phone = "123-456-7890";
    std::string email = "john.doe@example.com";
    int location = 1;
    std::string title = "Manager";
    std::string department = "Sales";

    EmployeeContact contact(first_name, last_name, business_phone, email, location, title, department);

    EXPECT_EQ(contact.get_title(), title);
    EXPECT_EQ(contact.get_department(), department);
}

TEST(EmployeeContactTest, SetAndGetTitle) {
    EmployeeContact contact;
    std::string new_title = "Director";

    contact.set_title(new_title);

    EXPECT_EQ(contact.get_title(), new_title);
}

TEST(EmployeeContactTest, SetAndGetDepartment) {
    EmployeeContact contact;
    std::string new_department = "Marketing";

    contact.set_department(new_department);

    EXPECT_EQ(contact.get_department(), new_department);
}

TEST(EmployeeContactTest, ShowContact) {
    EmployeeContact contact("Jane", "Doe", "321-654-0987", "jane.doe@example.com", 2, "Developer", "Engineering");

    testing::internal::CaptureStdout();
    contact.ShowContact();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = "Developer  Engineering  Jane Doe  2  321-654-0987  jane.doe@example.com\n";
    EXPECT_EQ(output, expected_output);
}

TEST(EmployeeContactTest, OutputStreamOperator) {
    EmployeeContact contact("Alice", "Smith", "555-555-5555", "alice.smith@example.com", 3, "HR", "Human Resources");

    std::stringstream ss;
    ss << contact;

    std::string expected_output = "HR  Human Resources  Alice Smith  3  555-555-5555  alice.smith@example.com";
    EXPECT_EQ(ss.str(), expected_output);
}

//ContractorContact class

TEST(ContractorContactTest, DefaultConstructor) {
    ContractorContact contact;

    EXPECT_EQ(contact.get_company(), ContractorContact::DEFAULT_COMPANY);
    EXPECT_EQ(contact.get_month(), ContractorContact::DEFAULT_MONTH);
}

TEST(ContractorContactTest, ParameterizedConstructor) {
    std::string first_name = "John";
    std::string last_name = "Doe";
    int months = 6;
    std::string company = "XYZ Inc";
    int location = 1;
    std::string business_phone = "123-456-7890";
    std::string email = "john.doe@example.com";

    ContractorContact contact(first_name, last_name, months, company, location, business_phone, email);

    EXPECT_EQ(contact.get_company(), company);
    EXPECT_EQ(contact.get_month(), months);
}

TEST(ContractorContactTest, SetAndGetCompany) {
    ContractorContact contact;
    std::string new_company = "New Company";

    contact.set_company(new_company);

    EXPECT_EQ(contact.get_company(), new_company);
}

TEST(ContractorContactTest, SetAndGetMonth) {
    ContractorContact contact;
    int new_months = 12;

    contact.set_month(new_months);

    EXPECT_EQ(contact.get_month(), new_months);
}

TEST(ContractorContactTest, ShowContact) {
    ContractorContact contact("Jane", "Doe", 3, "Tech Solutions", 2, "321-654-0987", "jane.doe@example.com");

    testing::internal::CaptureStdout();
    contact.ShowContact();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = "Tech Solutions    3    Jane Doe    2        jane.doe@example.com\n";
    EXPECT_EQ(output, expected_output);
}

TEST(ContractorContactTest, OutputStreamOperator) {
    ContractorContact contact("Alice", "Smith", 6, "Software Inc", 3, "555-555-5555", "alice.smith@example.com");

    std::stringstream ss;
    ss << contact;

    std::string expected_output = "Software Inc    6    Alice Smith    3        alice.smith@example.com";
    EXPECT_EQ(ss.str(), expected_output);
}


// contactlist class

TEST(ContactListTest, AddContact) {
    ContactList contacts;

    // Adding contacts
    Contact* contact1 = new Contact("John", "Doe", "123456789", "john.doe@example.com", 1);
    Contact* contact2 = new Contact("Jane", "Smith", "987654321", "jane.smith@example.com", 2);

    contacts.Insert(contact1);
    contacts.Insert(contact2);

    EXPECT_EQ(contacts.get_list(), contact1); // Assuming get_list() returns the head of the list
    EXPECT_EQ(contacts.get_list()->get_next(), contact2);
}

TEST(ContactListTest, SearchByName) {
    ContactList contacts;
    

    // Adding contacts
    Contact* contact1 = new Contact("John", "Doe", "123456789", "john.doe@example.com", 1);
    Contact* contact2 = new Contact("Jane", "Smith", "987654321", "jane.smith@example.com", 2);

    contacts.Insert(contact1);
    contacts.Insert(contact2);

    // Searching by name
    Name search_name("John", "Doe");
    Contact* found_contact = contacts.FindContact(search_name);

    // Checking if the correct contact is found
    EXPECT_EQ(found_contact, contact1);
}

TEST(ContactListTest, ClearList) {
    ContactList contacts;
    
    // Adding contacts
    contacts.Init();
    // Clearing the contact list
    contacts.ClearList();

    // Checking if the list is empty after clearing
    EXPECT_EQ(contacts.get_list(), nullptr);
}

// addressbook class

TEST(AddressBookTest, DefaultConstructor) {
    AddressBook address_book;
    EXPECT_EQ(AddressBook::DEFAULT_COMPANY_NAME, address_book.get_company_name());
}

TEST(AddressBookTest, ConstructorWithCompanyName) {
    std::string company_name = "Test Company";
    AddressBook address_book(company_name);
    EXPECT_EQ(company_name, address_book.get_company_name());
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

