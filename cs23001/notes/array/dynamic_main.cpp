#include <cstdlib>
#include <iostream>
#include "array.hpp"


int main() {

	darray d(3);

	darray copy(d);
	darray copy_two = d;  // Calls copy constructor
	copy = d;  // Calls assignment operator


	d[0] = 3;
	d[1] = 4;
	d[2] = 10;

	d.reset_capacity(2);

	std::cout << d;
	return 0;
}