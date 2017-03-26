//  String class test program
//
//  Name:  Donald Harmon
//  Tests: comparison operator overload, uses all constructors
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main () {
    
    {
        // Testing that all constructors null termination is equal
        // SETUP FIXTURE
        String str;
        String str_two('\0');
        String str_three("\0");

        // TEST 
        assert(str == str_two);
        assert(str == str_three);
        assert(str_two == str_three);

        // Other way around
        assert(str_two == str);
        assert(str_three == str);
        assert(str_three == str_two);

        // VERIFY
        std::cout << str << " == " << str_two << std::endl;
    }

    {
        // SETUP FIXTURE
        String str("I'm going to be equal to the other guy");

        // TEST 
        assert(str == "I'm going to be equal to the other guy");

        // VERIFY
        std::cout << str << " == I'm going to be equal to the other guy";
    }

    {
        // SETUP FIXTURE
        String str("I'm not going to be equal to the other guy");

        // TEST 
        assert(!(str == "I'm going to try to be equal to the other guy"));

        // VERIFY
        std::cout << str << " != I'm going to try be equal to the other guy" << std::endl;
    }


    // TESTING VARIOUS ESCAPE CHARACTERS W/ DIFFERENT CONSTRUCTORS ---------------------------------------------------
    {
        // SETUP FIXTURE
        String str("\n");
        String str_two('\n');

        // TEST 
        assert(str == str_two);

        // VERIFY
        std::cout << str << " == " << str_two << std::endl;
    }

    {
        // SETUP FIXTURE
        String str('\t');
        String str_two("\t");

        // TEST
        assert(str == str_two);

        // VERIFY
        std::cout << "|" << str << "==" << str_two << "|" << std::endl;
    }

    {
        // SETUP FIXTURE
        String str('\r');
        String str_two("\r");

        // TEST / VERIFY
        assert(str == "\r");
        assert(str_two == '\r');
        assert(str == str_two);

        // PRINT / 
        std::cout << "carriage return == carriage return" << std::endl;
    }
    // DONE TESTING VARIOUS ESCAPE CHARACTERS W/ DIFFERENT CONSTRUCTORS ----------------------------------------------

    {
        // SETUP FIXTURE
        String str('q');
        String str_two("qqqqqqqqqqqqqqqqqqqqqqqqqqqqq");

        // TEST
        assert(str == "q");
        assert(str_two == "qqqqqqqqqqqqqqqqqqqqqqqqqqqqq");
        assert(!(str == str_two));

        // VERIFY
        std::cout << str << " != " << str_two << std::endl;
    }

    {
        // SETUP FIXTURE
        String str('q');
        String str_two("Q");

        // TEST
        assert(str == "q");
        assert(str_two == 'Q');
        assert(!(str == str_two));

        // VERIFY
        std::cout << str << " != " << str_two << std::endl;
    }

    {
        // SETUP FIXTURE
        String str(' ');
        String str_two("  ");

        // TEST
        assert(str == " ");
        assert(str_two == "  ");
        assert(!(str == str_two));

        // VERIFY
        std::cout << '|' << str << '|' << " != " << '|' << str_two << '|' << std::endl;
    }

    {
        // SETUP FIXTURE (255 characters)
        String str("123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567");

        // TEST
        assert(str == "123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567");
    
        // Verify
        std::cout << str << std::endl <<  " == " << std::endl << "123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567" << std::endl;
    }

    {
        // SETUP FIXTURE (255 characters)
        String str("123456781234567812345678 12345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456");

        // TEST
        assert(str == "123456781234567812345678 12345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456");
    
        // Verify
        std::cout << str << std::endl <<  " == " << std::endl << "123456781234567812345678 12345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456781234567812345678123456" << std::endl;
    }

    {
        // SETUP FIXTURE
        String str("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
   
        // TEST / VERIFY
        assert(str == "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    }

    std::cout << "Done testing comparison operator" << std::endl;
}

