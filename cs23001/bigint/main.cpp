/**
 * Donald Harmon
 * bigint main file
 * CS23001
 */

// This program tests the implementations of bigint functions


//===========================================================================
// Basics for openning a file for milestone 2 of Project 1.
//
#include <iostream>
#include <fstream>
#include <ostream>
#include <cstdlib>
#include "bigint.hpp"


int main() {
    std::ifstream in("data1-1.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
        exit(1);
    }

    // Initializes ostream to pass to debug_print
    std::ostream & out = std::cout;

    
    bigint test;
    
    in >> test;
    
    test.debug_print(out);

    bigint test_two;

    in >> test_two;

    test_two.debug_print(out);

    bigint test_three;

    in >> test_three;

    test_three.debug_print(out);

    bigint test_four;

    in >> test_four;

    test_four.debug_print(out);

    bigint test_five;

    in >> test_five;

    test_five.debug_print(out);

    bigint test_six;

    in >> test_six;

    test_six.debug_print(out);
    

    //Until end of file
    //Read two bigints
    //Print them out
    //Add them together
    //Print out results
 
    in.close();
    return 0;
}

