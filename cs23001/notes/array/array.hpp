#include <iostream>

#ifndef CS2_ARRAY_HPP
#define CS2_ARRAY_HPP

class darray {

private:

	int * data;
	int cap;

private:

	darray(int new_cap, const darray & rhs);



public:

	// Constructors
	darray() : data(nullptr), cap (0) {}
	darray(int);

	// Copy constructor
	darray(const darray & rhs);

	// Assignment overload
	darray & operator=(darray rhs);

	// swap 
	void swap(darray & rhs);

	// Subscript overload
	int operator[](int) const;

	// Subscript overload (non-const)
	int & operator[](int);

	//reset capacity
	void reset_capacity(int new_cap);

	// Capacity
	int capacity() const;

	// Destructor
	~darray();

};

std::ostream & operator<<(std::ostream & out, const darray & ar);
std::istream & operator>>(std::istream & in, const darray & ar);


#endif 