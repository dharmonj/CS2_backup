/**
 * Donald Harmon
 * bigint header file
 * CS23001
 */

// This header file provides class template for "bigint", and MAX_DIGITS 

#include <cstdlib>
#include <ostream>
#include <iostream>

#ifndef BIGINT_H
#define BIGINT_H

const int MAX_DIGITS = 256;

class bigint
{
public:
	// Function Prototypes
	bigint();
  
	bigint(int init_numb);
  
	bigint(const char char_array[]);
 
	void debug_print(std::ostream& out) const;

	friend std::ostream & operator<<(std::ostream & out, const bigint & number);

	friend std::istream & operator>>(std::istream & in, bigint & that);

	bigint operator+(const bigint& rhs) const;

	bigint operator*(const bigint& rhs) const;

	int & operator[](const int i);

	const int & operator[](const int i) const;

	bool operator==(const bigint &);

	bigint times_digit(int single_digit) const;

	bigint times_10(int) const;

	// CHALLENGE MEMBERS
	void operator!();

	void find_lead_zeros();

private:
	// Static array to hold bigints digits
	int digits[MAX_DIGITS];
};

#endif /* BIGINT_H */
