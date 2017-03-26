//  String class test program
//
//  Name:  Donald Harmon
//  Tests: split, uses == and char[] constructor
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <vector>

//===========================================================================
int main (){

	{
		// Empty String test
		// SETUP FIXTURE
		String test;

		// TEST
		std::vector<String> v = test.split(';');

		// VERIFY
		assert(v[0] == "");
	}

	{
		// Single String test
		// SETUP FIXTURE
		String test("AbraKadabra!");

		// TEST
		std::vector<String> v = test.split('^');

		// VERIFY
		assert(v[0] == "AbraKadabra!");
	}

	{
		// Empty Strings between Strings test
		// SETUP FIXTURE
		String test("this;will;be;split;;there;will;be;a;;few;empty;;strings;");

		// TEST
		std::vector<String> v = test.split(';');

		// Verify
		assert(v[0] == "this");
		assert(v[1] == "will");
		assert(v[2] == "be");
		assert(v[3] == "split");
		assert(v[4] == "");
		assert(v[5] == "there");
		assert(v[6] == "will");
		assert(v[7] == "be");
		assert(v[8] == "a");
		assert(v[9] == "");
		assert(v[10] == "few");
		assert(v[11] == "empty");
		assert(v[12] == "");
		assert(v[13] == "strings");
		assert(v[14] == "");
	}

	{
		// SETUP FIXTURE
		String test("a--b");

		// TEST
		std::vector<String> v = test.split('-');

		// VERIFY
		assert(v[0] == "a");
		assert(v[1] == "");
		assert(v[2] == "b");
	}

	{
		// SETUP FIXTURE 
		String test("I am going to fill up a vector with all of my words! \n\t\r YAY!");

		// TEST
		std::vector<String> v = test.split(' ');

		// VERIFY
		assert(v[0] == "I");
		assert(v[1] == "am");
		assert(v[2] == "going");
		assert(v[3] == "to");
		assert(v[4] == "fill");
		assert(v[5] == "up");
		assert(v[6] == "a");
		assert(v[7] == "vector");
		assert(v[8] == "with");
		assert(v[9] == "all");
		assert(v[10] == "of");
		assert(v[11] == "my");
		assert(v[12] == "words!");
		assert(v[13] == "\n\t\r");
		assert(v[14] == "YAY!");
	}

	{
		// SETUP FIXTURE
		String test("-a--b");

		// TEST
		std::vector<String> v = test.split('-');

		// VERIFY
		assert(v[0] == "");
		assert(v[1] == "a");
		assert(v[2] == "");
		assert(v[3] == "b");
	}

	{
		// SETUP FIXTURE
		String test("$  $$   $");

		// TEST
		std::vector<String> v = test.split('$');

		// VERIFY
		assert(v[0] == "");
		assert(v[1] == "  ");
		assert(v[2] == "");
		assert(v[3] == "   ");
		assert(v[4] == "");
	}

	{
		// SETUP FIXTURE
		String test("0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 ");
	
		// TEST
		std::vector<String> v = test.split(' ');

		// VERIFY
		assert(v[0] == "0");
		assert(v[120] == "0");
		assert(v[149] == "0");
		// Ends in space, so last element empty string
		assert(v[150] == "");

		// TEST (0 Split)
		std::vector<String> v_two = test.split('0');

		// VERIFY
		assert(v_two[0] == "");
		assert(v_two[120] == " ");
		assert(v_two[149] == " ");
		assert(v_two[150] == " ");
	}

 


	std::cout << "Done testing split." << std::endl;


}