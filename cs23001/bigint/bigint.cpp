/**
 * Donald Harmon
 * bigint implementation file
 * CS23001
 */

// This program contains bigint class function implementations/definitions

#include <cstdlib>
#include <iostream>
#include <cassert>
#include "bigint.hpp"


// Determines whether int parameter is valid index for bigint[]
bool is_valid_index(int i){
	if(i<0||i>=MAX_DIGITS){
		return false;
	}
	return true;
}


// Default constructor, set all digits[] to 0
bigint::bigint(){

	for(int i = 0; i < MAX_DIGITS; ++i){
		digits[i]=0;  
	}

}


// Int constructor, initializes bigint to specified integer
bigint::bigint(int init_numb): bigint() {
  
	// Subtask inserts given number into array, least sig. digit first.
	int i = 0;
	while(init_numb > 0){
		digits[i++] = init_numb % 10;
		init_numb = init_numb / 10;
	}

}


// Char constructor, initializes bigint to specified char[]
bigint::bigint(const char char_array[]): bigint() {
  
	// Subtask counts the number of digits in char[]
	int i = 0;
	while(char_array[i] != '\0'){
		++i;
	}

	// Subtask inserts given char[] into array as integers
	int last_char = --i;
	int j = i;
	i = 0;
	while(i <= last_char){
		digits[i] = char_array[j--] - '0';
		++i;
	}

}


// Prints the bigint array in reverse order
void bigint::debug_print(std::ostream& out) const {

	out << "|";
	for(int i = MAX_DIGITS - 1; i >= 0; --i){
		out << digits[i] << "|";
	}

	// New line for cleanliness
	out << '\n';

}


// Overloaded << prints bigint "number" to the stream "out"
std::ostream & operator<<(std::ostream & out, const bigint & number){
	
	// Subtask finds the first non-zero digit in the array (from end)
	int digit_index = 0;
	for(int i = MAX_DIGITS -1; i >= 0; --i){
		if(number.digits[i] != 0 || i == 0){
			digit_index = i;
			break;
		}
	}

	// Subtask prints the bigint (79 digits per line, no lead zeros)
	const int FULL_LINE = 70;
	int digits_printed = 0;
	for(; digit_index >= 0; --digit_index){
		if(digits_printed==FULL_LINE){
			out << std::endl;
			digits_printed = 0;
		}
		out << number.digits[digit_index];
		digits_printed++;
	}

	// Return output stream
	return out;

}


// Overloaded == compares two bigints, returns T if match, F if not
bool bigint::operator==(const bigint& rhs){

	for(int i = 0; i < MAX_DIGITS; ++i){
		if(digits[i]!=rhs.digits[i]){
			return false;
		}
	}
	return true;

}


// Overloaded >> reads in any number of digits until a ";" is encountered
std::istream & operator>>(std::istream & in, bigint & receiver){

	// Subtask reads while there are chars and stores each dig. in char array
	int i = 0;
	char ch;
	char char_input[MAX_DIGITS + 1];
	while(in >> ch){

		// Store input character when appropriate
		if(ch!=';'){
			char_input[i] = ch;
			++i;
		}else if(ch==';'){
			break;	
		}
	}
	
	// Subtask inserts null terminator, calls char constructor on char[] of input
	char_input[i] = '\0';
	receiver = bigint(char_input);
	
	return in;

}


// Overloaded + takes a bigint parameter(rhs) and adds it to lhs bigint
bigint bigint::operator+(const bigint & rhs) const {

	bigint result;
	int carry = 0;
	int single_add = 0;

	// Subtask adds each index, checks if carry required, stores result
	for(int i = 0; i < MAX_DIGITS; ++i){
		single_add = digits[i] + rhs.digits[i] + carry;
		if(single_add > 9){
			carry = 1;
			single_add %= 10;
		}else{
			carry = 0;
		}
		result[i] = single_add;
	}

	return result;

}


// Overloaded [] takes an int parameter and returns the i-th digit (an int)
int & bigint::operator[](const int i){
	assert(is_valid_index(i));
	return digits[i];
}


// Overloaded [] is for const object access, works similarly to the above
const int & bigint::operator[](const int i) const{	
	assert(is_valid_index(i));
	return digits[i];
}


// times_digit multiplys the calling bigint by digit(0-9), returns result
bigint bigint::times_digit(int single_digit) const {
	bigint carry;
	bigint result;

	// Subtask models multiplication by hand, computes two separate bigints
	for(int i = 0; i < MAX_DIGITS; ++i){
		result[i] = (digits[i] * single_digit) % 10;
		if(i + 1 < MAX_DIGITS){
			carry[i + 1] = (digits[i] * single_digit) / 10;
		}
	}

	// Add the two separate bigints together and return the result
	result = result + carry;
	return result;
} 


// times_10 takes an int and multiplies calling bigint by 10^int (shift)
bigint bigint::times_10(int shift) const {
	
	bigint result;

	// If the shift is zero, return calling bigint (10^0 = 1, 1 * n = n)
	if(shift==0){
		return *this;

	// Else, if shift is positive, perform the shift
	}else if(shift > 0){
		for(int i = 0; i < MAX_DIGITS; ++i){
			if(i + shift < MAX_DIGITS){
				result.digits[i + shift] = digits[i];
			}
		}
	}

	return result;	
}


// Overloaded * operator multiplies bigints lhs & rhs, returns result
bigint bigint::operator*(const bigint& rhs) const{

	bigint product = 0;
	bigint temp = 0;

	// Subtask loops through digits in rhs, multiplies each by lhs(caller)
	// then multiplies temp by 10^i, and adds to running total (product)
	// This method models multiplication by hand, returns result when done
	for(int i = 0; i < MAX_DIGITS; ++i){
		temp = this->times_digit(rhs.digits[i]);
		product = product + temp.times_10(i);
	}

	return product;
}


// CHALLENGE - Factorial 
// Overloaded operator! finds factorial of input using bigint, prints
void bigint::operator!(){

	// Ask user for input
	std::cout << "Type a positive integer to find its factorial" << '\n';
	int input = 0;
	std::cin >> input;

	// If input > 0, find its factorial, print
	if(input > 0){
		*this = bigint(1);
		for(int i = input; i > 0; --i){
			*this = *this * i;
		}

		// Output and explanation
		std::cout << "Factorial of " << input << " is: " << '\n' << *this << '\n';
		std::cout << '\n' << "Calculated using a for loop," << '\n';
		std::cout << "finds product of input * all positive ints < input" << '\n';
		std::cout << '\n' << "loop code" << '\n';
		std::cout << "--------------------------------" << '\n'; 
		std::cout << "for(int i = input; i > 0; --i){" << '\n';
		std::cout << "	*this = *this * i;" << '\n';
		std::cout << "}" << '\n';
		std::cout << "--------------------------------" << '\n' << '\n';

	}
}


// CHALLENGE - Leading zeros
// find_lead_zeros() finds the number of leading zeros of calling bigint
void bigint::find_lead_zeros(){

	// Subtask finds first non-zero digit from index 0 up and displays
	for(int i = 0; i < MAX_DIGITS; ++i){
		if(digits[i]!=0){
			std::cout << "There are " << i << " lead zeros on:" << '\n';
			std::cout << *this << '\n';
			break;
		}
	}
}