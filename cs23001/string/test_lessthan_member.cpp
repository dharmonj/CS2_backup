//  String class test program
//
//  Name:  Donald Harmon
//  Tests: less than <, uses constructors, comparison
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main (){

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  left("\0");
		String  right("\0");

		// TEST
		assert(left == '\0');
		assert(right == '\0');
		assert(!(left < right));

		// VERIFY
		std::cout << left << " !< " << right << std::endl;
	}	

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  left("a");
		String  right("A");

		// TEST
		assert(left == 'a');
		assert(right == 'A');
		assert(!(left < right));

		// VERIFY
		std::cout << left << " !< " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  left("\n");
		String  right("\n");

		// TEST
		assert(left == '\n');
		assert(right == '\n');
		assert(!(left < right));

		// VERIFY
		std::cout << left << " !< " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  left("\t");
		String  right("\t");

		// TEST
		assert(left == '\t');
		assert(right == '\t');
		assert(!(left < right));

		// VERIFY
		std::cout << left << " !< " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  left("Z");
		String  right("a");

		// TEST
		assert(left == 'Z');
		assert(right == 'a');
		assert(left < right);

		// VERIFY
		std::cout << left << " < " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  left;
		String  right("A");

		// TEST
		assert(left == '\0');
		assert(right == 'A');
		assert(left < right);

		// VERIFY
		std::cout << left << " < " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  left(' ');
		String  right("!");

		// TEST
		assert(left == ' ');
		assert(right == '!');
		assert(left < right);

		// VERIFY
		std::cout << left << " < " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  left("ZZZZ");
		String  right("ZZZZ ");

		// TEST
		assert(left == "ZZZZ");
		assert(right == "ZZZZ ");
		assert(left < right);

		// VERIFY
		std::cout << left << " < " << right << "(space on end of right)" << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  left("ArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongString");
		String  right("ArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringaaaa");

		// TEST
		assert(left == "ArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongString");
		assert(right == "ArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringArbitrarilyLongStringaaaa");
		assert(left < right);

		// VERIFY
		std::cout << left << std::endl << " < " << std::endl << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  left("Tanzania");
		String  right("Tanzania");

		// TEST
		assert(left == "Tanzania");
		assert(right == "Tanzania");
		assert(!(left < right));

		// VERIFY
		std::cout << left << " !< " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  left("Areallybigstringthatyoumightthinkwouldbegreaterthanthelittletinyonei'mgoingtotestitagainst");
		String  right("a");

		// TEST
		assert(left == "Areallybigstringthatyoumightthinkwouldbegreaterthanthelittletinyonei'mgoingtotestitagainst");
		assert(right == 'a');
		assert(left < right);

		// VERIFY
		std::cout << left << " < " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String  left("Z");
		String  right("a");

		// TEST
		assert(left == 'Z');
		assert(right == 'a');
		assert(left < right);

		// VERIFY
		std::cout << left << " < " << right << std::endl;
	}

	{
		// SETUP FIXTURE
		String left("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		String right("A");

		// TEST / VERIFY
		assert(left == "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		assert(right == "A");
		assert(left < right);
	}


	std::cout << "Done testing lessthan member function" << std::endl;



}