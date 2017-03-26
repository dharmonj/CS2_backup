//  String class test program
//
//  Name:  Donald Harmon
//  Tests: substr, uses ==, length, and constructors
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main (){

	{
		// SETUP FIXTURE
		String test("");

		// TEST / VERIFY
		assert(test.substr(0, 1) == "");
		assert(test.substr(0, 1).is_null_terminated());
		assert(test.substr(-1, 0) == "");

		// End test
		assert(test.substr(0,10) == "");
		assert(test.substr(0,10).is_null_terminated());
		assert(test.substr(0,10).length() == 0);
	}

	{
		// SETUP FIXTURE
		String test("abc");

		// TEST / VERIFY
		// Start tests
		assert(test.substr(-3, 3) == "abc");
		assert(test.substr(-3, 3).length() == 3);
		assert(test.substr(-1000, 2) == "ab");
		assert(test.substr(-1000, 2).length() == 2);
		assert(test.substr(-1000, 2).is_null_terminated());
		assert(test.substr(0, 2) == "ab");
		assert(test.substr(0, 2).length() == 2);
		assert(test.substr(0, 2).is_null_terminated());

		// End tests
		assert(test.substr(2, 2) == "c"); 
		assert(test.substr(2, 2).length() == 1);
		assert(test.substr(2, 2).is_null_terminated());
		assert(test.substr(3, 455) == "");
		assert(test.substr(3, 455).length() == 0);
		assert(test.substr(3, 455).is_null_terminated());

		// Single test
		assert(test.substr(0, 1) == 'a');
		assert(test.substr(0, 1).length() == 1);

		// Full string test
		assert(test.substr(0, 3) == "abc");
		assert(test.substr(0, 3).length() == 3);
	}

	{
		// SETUP FIXTURE
		String test("A rather medium sized String that I will test with and stuff");

		// TEST / VERIFY
		// Full String
		assert(test.substr(0, 60) == "A rather medium sized String that I will test with and stuff");
		assert(test.substr(0, 60).length() == 60);

		// Start tests
		assert(test.substr(-10, 5) == "A rat");
		assert(test.substr(-10, 5).length() == 5);
		assert(test.substr(0, 10) == "A rather m");
		assert(test.substr(0, 10).length() == 10);

		// Middle tests
		assert(test.substr(9, 19) == "medium sized String");
		assert(test.substr(9, 19).length() == 19);
		assert(test.substr(41, 4) == "test");
		assert(test.substr(41, 4).length() == 4);

		// End tests
		assert(test.substr(60, 20) == "");
		assert(test.substr(60, 20).length() == 0);
		assert(test.substr(60, 20).is_null_terminated());
		assert(test.substr(59, 1) == 'f');
		assert(test.substr(59, 20) == 'f');
		assert(test.substr(59, 20).length() == 1);
		assert(test.substr(59, 20).is_null_terminated());
	}

	{
		// SETUP FIXTURE (LONG STRING)
		String test("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	
		// TEST / VERIFY
		// Full String
		assert(test.substr(0, 500) == "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		assert(test.substr(0, 500).length() == 500);
		assert(test.substr(0, 500).is_null_terminated());
		assert(test.substr(0, 600) == "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		assert(test.substr(0, 600).length() == 500);

		// Start tests
		assert(test.substr(0, 10) == "0123456789");
		assert(test.substr(0, 10).length() == 10);

		// Middle tests
		assert(test.substr(9, 10) == "9012345678");
		assert(test.substr(9, 10).length() == 10);
		assert(test.substr(9, 10).is_null_terminated());
		assert(test.substr(99, 100) == "9012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678");
		assert(test.substr(99, 100).length() == 100);

		// End tests
		assert(test.substr(500, 100) == "");
		assert(test.substr(500, 1) == "");
		assert(test.substr(500, 100).length() == 0);
		assert(test.substr(499, 1) == "9");
		assert(test.substr(499, 1).length() == 1);
		assert(test.substr(399, 100) == "9012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678");
		assert(test.substr(399, 500) == "90123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		assert(test.substr(399, 500).length() == 101);
		assert(test.substr(399, 500).is_null_terminated());
		assert(test.substr(399, 100).length() == 100);
		assert(test.substr(399, 100).is_null_terminated());
	}



	std::cout << "Done testing substr method." << std::endl;

}
