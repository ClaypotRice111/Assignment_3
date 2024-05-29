//============================================================================
// File Name : main.cpp
// Author : Weiaho Huang
// Copyright : You can copy it or modify it. Unlness you use it on business or profitability activiy.
// Description : This program is to .....

// Disclaimer: If this program works obviously it's written by the above author. If it doesn't I don't know who wrote it.
// Revision History:
// Date                      Version         Change ID               Author                     Comment
// 05-27-2024                 1.0            2b35889                 Weihao Huang               create the project
// 05-28-2024                 1.1			 d5c9fb4                 Weihao Huang               build class skeletons
// 05-29-2024				  1.2			 af76408				 Weihao Huang 				update data structure portion
//============================================================================


#include <iostream>
#include "includes/AddressBook.h"

using namespace std;



int main(int argc, char* argv[]) {
	AddressBook address_book;
	address_book.Init();
	address_book.Run();
	address_book.~AddressBook();

	return 0;
}