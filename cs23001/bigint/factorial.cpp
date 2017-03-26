/**
 * Donald Harmon
 * Factorial Challenge file
 * CS23001
 */

// This program demonstrates factorial operator and find_lead_zeros() method


#include <iostream>
#include <fstream>
#include <ostream>
#include <cstdlib>
#include "bigint.hpp"

void how_to();

int main() {

	// Loop allows user to find multiple factorials
	// Instructions for finding trailing zeros mathematically printed on exit
	std::cout << "Hello!" << '\n' << "Want to find a factorial? [y/n]" << '\n';
	char input = 'n';
	std::cin >> input;
	std::cout << '\n';
	while(input != 'n'){
		if(input == 'y'){
			bigint test;
			!test;
			test.find_lead_zeros();
		}
		std::cout << '\n' << "Want to find another factorial? [y/n]" << '\n';
		std::cin >> input;
		std::cout << '\n';
	}
	std::cout << "Thanks for using the factorial program!" << '\n' << '\n';
	how_to();

	return 0;
}

// How to find your own factorial instruction function
void how_to(){
	std::cout << "If YOU want to find a factorial's trailing zeros:" << '\n';
	std::cout << "Count the pairs of 2's and 5's" << '\n';
	std::cout << "2*5=10, a 10 creates a trailing zero" << '\n';
	std::cout << "You need to find all multiples of 2 and 5" << '\n';
	std::cout << "Multiples of 25 count as 2 multiples of 5 (5x5=25)" << '\n';
	std::cout << "You find these pairs in the factorial's expansion" << '\n';
	std::cout << "5 will have less multiples than 2 in any expansion" << '\n';
	std::cout << "So the number of multiples of 5 in the expansion," << '\n';
	std::cout << "is equal to the number of trailing zeros" << '\n' << '\n';
	std::cout << "Here's an example:" << '\n';
	std::cout << "With 25, 50, 75, and 100 counted as 2 multiples of 5," << '\n';
	std::cout << " 5 10 15 20 25 30 35 40 45 50" << '\n';
	std::cout << "55 60 65 70 75 80 85 90 95 100" << '\n';
	std::cout << " 2 +2 +2 +2 +4 +2 +2 +2 +2 +4" << '\n';
	std::cout << "= 24 = #of trailing zeros on 100!" << '\n';
}