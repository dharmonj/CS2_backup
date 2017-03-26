//  String class test program
//
//  Name:  Donald Harmon
//  Tests: char constructor, uses ==
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main (){

    {
        // SETUP FIXTURE
        
        // TEST
        String str('\0');

        // VERIFY
        assert(str == '\0');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('a');

        // VERIFY
        assert(str == "a");

        // PRINT
        std::cout << str << " == a" << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('a');

        // VERIFY
        assert(!(str == "A"));

        // PRINT
        std::cout << str << " != A" << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(';');

        // VERIFY
        assert(str == ";");

        // PRINT
        std::cout << str << " == ;" << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str(' ');

        // VERIFY
        assert(str == " ");
    }

    {
        // SETUP FIXTURE
        // TEST
        String str('0');

        // VERIFY
        assert(str == '0');

        // PRINT
        std::cout << str << " == 0" << std::endl;
    }

    {
        // SETUP FIXTURE
        // TEST
        String str('\n');

        // VERIFY
        assert(str == '\n');

        // PRINT
        std::cout << str << " == " << "\n" << std::endl;
    }

    {
        // SETUP FIXTURE
        // TEST
        String str('\t');

        // VERIFY
        assert(str == '\t');

        // PRINT
        std::cout << "|" << str << "==" << "\t" << "|" << std::endl;
    }

    {
        // SETUP FIXTURE
        // TEST
        String str('\r');

        // VERIFY
        assert(str == '\r');

        // PRINT
        std::cout << "carriage return == carriage return" << std::endl;
        //std::cout << '\r == \r' << std::endl; // WHY DOES THIS RESULT IN A NUMBER WHEN UNCOMMENTED? I AM VERY CURIOUS!
        //std::cout << "|" << str << " == " << '\r' << "|" << std::endl; // ALSO NOT SURE ABOUT WHAT THIS PRODUCES, CURIOUS!
    }

    
    std::cout << "Done testing char constructor." << std::endl;

}

