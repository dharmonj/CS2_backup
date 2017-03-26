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
    //std::ostream & out = std::cout;
    
    // Declare bigints for input and computation
    bigint rhs;
    bigint lhs;   

    // Loop reads in two bigints, prints each, adds, and prints result
    while (in >> lhs && in >> rhs) {
        
   	
        std::cout << "lhs       = " << lhs << std::endl;
        lhs.debug_print(out);
        std::cout << "rhs       = " << rhs << std::endl;
        bigint result = lhs + rhs; 
        std::cout << "lhs + rhs = " << result << std::endl << std::endl;

      
    }

    //Until end of file
    //Read two bigints
    //Print them out
    //Add them together
    //Print out results
    

    in.close();
    return 0;
}