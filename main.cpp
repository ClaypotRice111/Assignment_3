//============================================================================
// File Name : main.cpp
// Author : Weiaho Huang
// Copyright : You can copy it or modify it. Unlness you use it on business or profitability activiy.
// Description : The TP Communications Address Book application is a console-based tool that allows employees and contractors to manage 
//               and search contact information. It utilizes linked list implementation, abstract classes, polymorphism, and operator overloading. 

// Disclaimer: If this program works obviously it's written by the above author. If it doesn't I don't know who wrote it.
// Revision History:
// Date                      Version         Change ID               Author                     Comment
// 05-27-2024                 1.0            2b35889                 Weihao Huang               create the project
// 05-28-2024                 1.1			 d5c9fb4                 Weihao Huang               build class skeletons
// 05-29-2024				  1.2			 af76408				 Weihao Huang 				update data structure portion
// 05-29-2024                 2.0            73edac6                 Weihao Huang               full version
// 06-03-2024                 2.1            52bd6e4                 Weihao Huang               fixed bugs
// 06-03-2024                 2.2            affabe2                 Weihao Huang               change logical insert before to insert after
//============================================================================


#include <iostream>
#include "includes/AddressBook.h"



using namespace std;



int main(int argc, char* argv[]) {
    AddressBook* address_book = new AddressBook();
    address_book->Init();
    address_book->Run();
    delete address_book;
    return 0;
}
