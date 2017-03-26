//  String class test program
//
//  Name:  Donald Harmon
//  Tests: all relational free functions, uses constructors, comparison method, < method, 
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main (){

	// TESTS FOR operator==(const char[], const String)
	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("\0");

		// TEST
		assert(right == '\0');
		assert("\0" == right);

		// VERIFY
		std::cout << "\0" << " == " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");

		// TEST
		assert(right == "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
		assert("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" == right);

		// VERIFY
		std::cout << "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" << " == " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("cheese");

		// TEST
		assert(right == "cheese");
		assert(!("bananas" == right));

		// VERIFY
		std::cout << "bananas" << " != " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");

		// TEST
		assert(right == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");
		assert("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd" == right);

		// VERIFY
		std::cout << "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd" << std::endl << " == " << std::endl << right << std::endl;
	}

	// TESTS FOR operator==(char, const String)
	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("\n");


		// TEST
		assert(right == "\n");
		assert('\n' == right);

		// VERIFY
		std::cout << '\n' << " == " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("\0");


		// TEST
		assert(right == "\0");
		assert('\0' == right);

		// VERIFY
		std::cout << '\0' << " == " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("Q");


		// TEST
		assert(right == "Q");
		assert('Q' == right);

		// VERIFY
		std::cout << 'Q' << " == " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");


		// TEST
		assert(right == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");
		assert(!('a' == right));

		// VERIFY
		std::cout << 'a' << " != " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("|");


		// TEST
		assert(right == "|");
		assert('|' == right);

		// VERIFY
		std::cout << '|' << " == " << right << std::endl;
	}

	// TESTS FOR operator<(const char[], const String)
	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right(" ");


		// TEST
		assert(right == " ");
		assert('\n' < right);

		// VERIFY
		std::cout << '\n' << " < " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("cabbagepatch");


		// TEST
		assert(right == "cabbagepatch");
		assert("cabbage" < right);

		// VERIFY
		std::cout << "cabbage" << " < " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("zimbabwe");


		// TEST
		assert(right == "zimbabwe");
		assert('Z' < right);

		// VERIFY
		std::cout << 'Z' << " < " << right << std::endl;
	}

	// TESTS FOR operator<(char, const String)
	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right(" ");


		// TEST
		assert(right == " ");
		assert('\n' < right);

		// VERIFY
		std::cout << '\n' << " < " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");

		// TEST
		assert(right == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");
		assert('Z' < right);

		// VERIFY
		std::cout << 'Z' << " < " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String right("a");


		// TEST
		assert(right == "a");
		assert('F' < right);

		// VERIFY
		std::cout << 'F' << " < " << right << std::endl;
	}

	// TESTS FOR operator<=(const String, const String)
	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left;
		String right;

		// TEST
		assert(left <= right);
		assert(left == "\0");
		assert(right == "\0");

		// VERIFY
		std::cout << left << " <= " << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("Asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");
		String right("a");

		// TEST
		assert(left <= right);
		assert(left == "Asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");
		assert(right == "a");

		// VERIFY
		std::cout << left << " <= " << right << std::endl;
	}	

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");
		String right("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");

		// TEST
		assert(left <= right);
		assert(left == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");
		assert(right == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");

		// VERIFY
		std::cout << left << std::endl << " <= " << std::endl << right << std::endl;
	}

	// TESTS FOR operator!=(const String, const String)
	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");
		String right("asdfasdfasdfasdf fasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");

		// TEST
		assert(left != right);
		assert(left == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");
		assert(right == "asdfasdfasdfasdf fasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");

		// VERIFY
		std::cout << left << std::endl << " != " << std::endl << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("a");
		String right("A");

		// TEST
		assert(left != right);
		assert(left == "a");
		assert(right == "A");

		// VERIFY
		std::cout << left << std::endl << " != " << std::endl << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left(" ");
		String right("  ");

		// TEST
		assert(left != right);
		assert(left == " ");
		assert(right == "  ");

		// VERIFY
		std::cout << left << std::endl << " != " << std::endl << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("\n");
		String right;

		// TEST
		assert(left != right);
		assert(left == "\n");
		assert(right == "\0");

		// VERIFY
		std::cout << left << std::endl << " != " << std::endl << right << std::endl;
	}

	// TESTS FOR operator>=(const String, const String)
	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("a");
		String right("A");

		// TEST
		assert(left >= right);
		assert(left == "a");
		assert(right == "A");

		// VERIFY
		std::cout << left << std::endl << " >= " << std::endl << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("A");
		String right("A");

		// TEST
		assert(left >= right);
		assert(left == "A");
		assert(right == "A");

		// VERIFY
		std::cout << left << std::endl << " >= " << std::endl << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");
		String right("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");

		// TEST
		assert(left >= right);
		assert(left == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");
		assert(right == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");

		// VERIFY
		std::cout << left << std::endl << " >= " << std::endl << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("thisonesgonnabegreat, erthantherightone");
		String right("thisonesgonnabegreat, erthantheright");

		// TEST
		assert(left >= right);
		assert(left == "thisonesgonnabegreat, erthantherightone");
		assert(right == "thisonesgonnabegreat, erthantheright");

		// VERIFY
		std::cout << left << std::endl << " >= " << std::endl << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfas 1234");
		String right("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfas");

		// TEST
		assert(left >= right);
		assert(left == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfas 1234");
		assert(right == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfas");

		// VERIFY
		std::cout << left << std::endl << " >= " << std::endl << right << std::endl;
	}

	// TESTS FOR operator>(const String, const String)
	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("thisonesgonnabegreat, erthantherightone");
		String right("thisonesgonnabegreat, erthantheright");

		// TEST
		assert(left >= right);
		assert(left == "thisonesgonnabegreat, erthantherightone");
		assert(right == "thisonesgonnabegreat, erthantheright");

		// VERIFY
		std::cout << left << std::endl << " > " << std::endl << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfas 1234");
		String right("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfas");

		// TEST
		assert(left >= right);
		assert(left == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfas 1234");
		assert(right == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfas");

		// VERIFY
		std::cout << left << std::endl << " > " << std::endl << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("abc");
		String right("123");

		// TEST
		assert(left >= right);
		assert(left == "abc");
		assert(right == "123");

		// VERIFY
		std::cout << left << std::endl << " > " << std::endl << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left(" ");
		String right("\n");

		// TEST
		assert(left >= right);
		assert(left == " ");
		assert(right == "\n");

		// VERIFY
		std::cout << left << std::endl << " > " << std::endl << right << std::endl;
	}

	{
		//------------------------------------------------------
		// SETUP FIXTURE
		String left("thisonesnotgonnabegreat, erthantherightone");
		String right("tthisonesgonnabegreat, erthantheleft");

		// TEST
		assert(!(left >= right));
		assert(left == "thisonesnotgonnabegreat, erthantherightone");
		assert(right == "tthisonesgonnabegreat, erthantheleft");

		// VERIFY
		std::cout << left << std::endl << " >= " << std::endl << right << std::endl;
	}

	{
		// SETUP FIXTURE
		String left("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		String right("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	
		// TEST
		assert(left >= right);
		assert(left == "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		assert(right == "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		std::cout << "500 char >= 500 same char test passed" << '\n';
	}

	{
		// SETUP FIXTURE
		String left("z01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		String right("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	
		// TEST
		assert(left >= right);
		assert(left == "z01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		assert(right == "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		std::cout << "500 char >= 500 same char test passed" << '\n';
	}

	{
		// SETUP FIXTURE
		String left("z01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		String right("z021234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	
		// TEST
		assert(!(left >= right));
		assert(left == "z01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		assert(right == "z021234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
		std::cout << "500 char >= 500 same char test passed" << '\n';
	}

	std::cout << "Done testing free relationals" << std::endl;

}