//  String class test program
//
//  Name:  Donald Harmon
//  Tests: find char, uses ==, and constructors
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main (){

	{
		// SETUP FIXTURE
		String searched;

		// TEST / VERIFY
		assert(searched.find(' ', 0) == -1);
		assert(searched.find('A', 1) == -1);
		assert(searched.find('A', -1) == -1);
	}

	{
		// SETUP FIXTURE
		String searched("0123456789 ");

		// TEST / VERIFY
		assert(searched.find('0', 0) == 0);
		assert(searched.find('0', 1) == -1);
		assert(searched.find('1', 0) == 1);
		assert(searched.find('1', 1) == 1);
		assert(searched.find('9', 0) == 9);
		assert(searched.find('9', 9) == 9);
		assert(searched.find('8', 9) == -1);
		assert(searched.find('4', 0) == 4);
		assert(searched.find('4', 4) == 4);
		assert(searched.find('3', 4) == -1);
		assert(searched.find('3', 9) == -1);
		assert(searched.find('a', 0) == -1);
		assert(searched.find(' ', 0) == 10);
		assert(searched.find(' ', 10) == 10);
	}

	{
		// SETUP FIXTURE
		String searched("this will be very long indeed this will be very long indeed this will be very long indeed this will be very long indeed this will be very long indeed this will be very long indeed this will be very long indeed this will be very long indeed this will be very long indeed this will be very long indeed *");
	
		// TEST / VERIFY
		assert(searched.find('i', 0) == 2);
		assert(searched.find('i', 3) == 6);
		assert(searched.find('i', 7) == 23);
		assert(searched.find('*', 0) == 300);
		assert(searched.find('*', 300) == 300);
		assert(searched.find(' ', 0) == 4);
		assert(searched.find(' ', 5) == 9);
		assert(searched.find('%', 0) == -1);
		assert(searched.find('\n', 0) == -1);
	}


	std::cout << "Done testing find() character." << std::endl;

}
