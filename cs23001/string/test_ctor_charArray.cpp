//  String class test program
//
//  Name:  Donald Harmon
//  Tests: char array constructor, uses ==
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{

    {
        // SETUP FIXTURE
        
        // TEST
        String str("");

        // VERIFY
        assert(str == '\0');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("a");

        // VERIFY
        assert(str == "a");

        // PRINT
        std::cout << str << " == a" << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("a");

        // VERIFY
        assert(!(str == "A"));

        // PRINT
        std::cout << str << " != A" << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("test");

        // VERIFY
        assert(str == "test");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");

        // VERIFY
        assert(str == "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasd");
    }

    {
        // SETUP FIXTURE
        // TEST
        String str("9876asdf1234;lkj");

        // VERIFY
        assert(str == "9876asdf1234;lkj");

        // PRINT
        std::cout << str << " == 9876asdf1234;lkj" << std::endl;
    }

    {
        // SETUP FIXTURE
        // TEST
        String str("99 cups of coffee on the wall, take one down and drink it, 1 function in the implementation file");

        // VERIFY
        assert(str == "99 cups of coffee on the wall, take one down and drink it, 1 function in the implementation file");

        // PRINT
        std::cout << str << std::endl << " == " << std::endl << "99 cups of coffee on the wall, take one down and drink it, 1 function in the implementation file" << std::endl;
    }

    {
        // SETUP FIXTURE
        // TEST
        String str("Everyone loves Testing constructors!");

        // VERIFY
        assert(!(str == "everyone loves testing constructors!"));

        // PRINT
        std::cout << str << " != everyone loves testing constructors!" << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str("131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] \"GET /~darci/ HTTP/1.0\" 200 5625");

        // VERIFY
        // Testing apache log file format for char constructor
        assert(str == "131.123.47.176 - - [18/Sep/2002:12:05:25 -0400] \"GET /~darci/ HTTP/1.0\" 200 5625");

    }

    {
        // SETUP FIXTURE

        // TEST
        String str("01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");

        // VERIFY
        assert(str == "01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
    }
    
    std::cout << "Done testing char array constructor." << std::endl;

}

