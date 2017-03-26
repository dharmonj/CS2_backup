//  String class test program
//
//  Name:  Donald Harmon
//  Tests: find string, uses ==, and char[] constructor
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
		assert(searched.find("", 0) == 0);
		assert(searched.find("asdf", 0) == -1);
		assert(searched.find("", 1) == -1);
	}

	{
		// SETUP FIXTURE
		String searched('%');

		// TEST / VERIFY
		assert(searched.find("", 0) == 0);
		assert(searched.find("", 1) == 1);
		assert(searched.find("", 2) == -1);
		assert(searched.find("%", 0) == 0);
		assert(searched.find("%", 1) == -1);
		assert(searched.find(" ", 0) == -1);
	}

	{
		// SETUP FIXTURE
		String searched("aaaaaa                                                     bbbbbb");

		// TEST / VERIFY
		// Empty tests
		assert(searched.find("", 0) == 0);
		assert(searched.find("", 10) == 10);

		// Start tests
		assert(searched.find("aaaaaa", 0) == 0);
		assert(searched.find("aaaaaaa", 0) == -1);
		assert(searched.find("aaaaaa", 1) == -1);

		// End tests
		assert(searched.find("bbba", 0) == -1);
		assert(searched.find("bbbbbb", 0) == 59);

		// Various
		assert(searched.find(" b", 0) == 58);
		assert(searched.find("                 ", 0) == 6);
		assert(searched.find(" ", 6) == 6);
		assert(searched.find("                                                     b", 0) == 6);
		assert(searched.find("                                                     b", 6) == 6);
	}

	{
		// SETUP FIXTURE
		String searched("I am a long string, I'm going to be searched! I'm so stringing excited to help with testing the find string function.   I am a long string, I'm going to be searched! I'm so stringing excited to help with testing the find string function.   I am a long string, I'm going to be searched! I'm so stringing excited to help with testing the find string function.   I am a long string, I'm going to be searched! I'm so stringing excited to help with testing the find string function.   I am a long string, I'm going to be searched! I'm so stringing excited to help with testing the find string function.   I'm the end!");

		// TEST / VERIFY
		// Empty
		assert(searched.find("", 0) == 0);
		assert(searched.find("", 100) == 100);
		assert(searched.find("", 650) == -1);

		// Start tests
		assert(searched.find("I am a long string, I'm going to be searched!", 0) == 0);
		assert(searched.find("I'm so stringing excited to help with testing the find string function", 0) == 46);

		// End tests
		assert(searched.find("I'm the end!", 0) == 600);
		assert(searched.find("I'm the end!", 600) == 600);
		assert(searched.find("I'm the end! ", 600) == -1);
		assert(searched.find("I'm the end!", 601) == -1);

		// Various
		assert(searched.find("I am a long string, I'm going to be searched!", 1) == 120);
		
		// Full String
		assert(searched.find("I am a long string, I'm going to be searched! I'm so stringing excited to help with testing the find string function.   I am a long string, I'm going to be searched! I'm so stringing excited to help with testing the find string function.   I am a long string, I'm going to be searched! I'm so stringing excited to help with testing the find string function.   I am a long string, I'm going to be searched! I'm so stringing excited to help with testing the find string function.   I am a long string, I'm going to be searched! I'm so stringing excited to help with testing the find string function.   I'm the end!", 0) == 0);
		// Same
		assert(searched.find(searched, 0) == 0);
		assert(searched.find(searched, 1) == -1);
	}



	std::cout << "Done testing find() String." << std::endl;

}
