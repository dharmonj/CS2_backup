//  String class test program
//
//  Name:  Donald Harmon
//  Tests: default constructor, uses ==
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str;

        // VERIFY
        assert(str == '\0');
        std::cout << str << "== \0" << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str;

        // VERIFY
        assert('\0' == str);
    }
    
    std::cout << "Done testing default constructor." << std::endl;

}

