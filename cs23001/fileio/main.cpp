/**
 * Donald Harmon
 * This file counts the number of non-whitespace chars, and words in "io_file.txt" 
 * CS23001
 */


#include <iostream>
#include <fstream>
#include <ostream>
#include <cstdlib>

int main() {

		// Open stream to read in characters
		std::ifstream in("io_file.txt");    // Define stream for input
		if(!in) {                           // Make sure it opened correctly.
			std::cerr << "Could not open io_file.txt, exiting." << std::endl;
			exit(1);
		}

		// Count non-whitespace characters
		int num_of_ch = 0;
		char ch;

		// While a char is found add one to count of chars
		while(in >> ch){
			num_of_ch++;
		}

		// Close input stream to reset character pointer 
		in.close();

		// Open Stream to read in words
		std::ifstream in_two("io_file.txt");    // Define stream for input
		if(!in_two) {                           // Make sure it opened correctly.
			std::cerr << "Could not open io_file.txt, exiting." << std::endl;
			exit(1);
		}

		// Count words
		int num_of_words = 0;
		char chars[100];
    
		// While a word is found add one to count of words
		while(in_two >> chars){
			num_of_words++;    	
		}

		// Output the number of chars and words
		std::cout << "# of characters: " << num_of_ch << '\n';
		std::cout << "# of words: " << num_of_words << '\n';

		// Close the stream
		in_two.close();
		return 0;

}