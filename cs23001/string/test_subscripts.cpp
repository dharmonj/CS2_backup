//  String class test program
//
//  Name:  Donald Harmon
//  Tests: subscript overloads, uses all constructors and == 
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main () {

	// ACCESSOR TESTS
	{
		// SETUP FIXTURE
		const String str("0123456789");

		// TEST 
		assert(str[3] == '3');
		assert(str[9] == '9');

		// VERIFY
		std::cout << str[3] << " == " << "3" << std::endl;
		std::cout << str[9] << " == " << "9" << std::endl;
	}	

	{
		// SETUP FIXTURE
		const String str("012345 789");
		
		// TEST
		assert(str[6] == ' ');

		//VERIFY
		std::cout << str[6] << " == " << " " << std::endl;

	}

	{
		// SETUP FIXTURE
		const String str("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");

		// TEST
		assert(str[254] == 'd');

		// VERIFY
		std::cout << str[254] << " == " << "d" << std::endl;
	}

	{
		// SETUP FIXTURE
		const String str("coffee = new code");

		// TEST
		assert(str[6] == ' ');
		assert(str[7] == '=');

		// VERIFY
		std::cout << str[6] << " == " << " " << std::endl;
		std::cout << str[7] << " == " << "=" << std::endl;

	}
	{
		// SETUP FIXTURE
		const String str("cheese");

		// TEST
		char test = str[4];

		// VERIFY
		assert(test == 's');
	}

	{
		// SETUP FIXTURE
		String str("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	
		// TEST / VERIFY
		assert(str[499] == '9');
		assert(str[0] == '0');
		assert(str[2] == '2');
	}

	// MUTATOR TESTS
	{
		// SETUP FIXTURE
		String str("THIS is going to be changed");

		// TEST
		str[0] = 'c';
		str[1] = 'o';
		str[2] = 'd';
		str[3] = 'e';

		// VERIFY
		assert(str == "code is going to be changed");
	}
	{
		// SETUP FIXTURE
		String str("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");

		// TEST
	  str[254] = '&';

		// VERIFY
		assert(str == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfas&");
	}
	{
		// SETUP FIXTURE
		String str("cake");

		// TEST
		str[0] = 'L';

		// VERIFY
		assert(str == "Lake");

		// TEST
		str[0] = 'R';

		// VERIFY
		assert(str == "Rake");

		// TEST
		str[0] = 'B';

		// VERIFY
		assert(str == "Bake");

		// TEST
		str[0] = 't';

		// VERIFY
		assert(str == "take");

		// TEST
		str[0] = 'f';

		// VERIFY
		assert(str == "fake");

		// TEST
		str[0] = 'M';

		// VERIFY
		assert(str == "Make");

		// TEST
		str[0] = 's';

		// VERIFY
		assert(str == "sake");
	}

	{
		// SETUP FIXTURE
		String str("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	
		// TEST 
		str[499] = '\n';

		// VERIFY
		assert(str == "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678\n");
	}
	
	std::cout << "Done testing subscript operators" << std::endl;

}