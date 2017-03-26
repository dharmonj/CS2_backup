#include <iostream>
#include <cstdlib>
#include <cassert>
#include "array.hpp"


// int constructor
darray::darray(int new_cap) : cap(new_cap) {
	data = new int[new_cap];
}


// Copy constructor
darray::darray(const darray & rhs) : darray(rhs.cap){

		for(int i = 0; i < cap; ++i){
			data[i] = rhs.data[i];
		}
	
}


darray::darray(int new_cap, const darray & rhs) : darray(new_cap) {

	int smaller = new_cap < rhs.cap ? new_cap : rhs.cap;

	for(int i = 0; i < smaller; ++i){
		data[i] = rhs.data[i];
	}

}

// Swap function
void darray::swap(darray & rhs){

	int temp_cap = cap;
	cap = rhs.cap;
	rhs.cap = temp_cap;

	int * temp_data = data;
	data = rhs.data;
	rhs.data = temp_data;

}


// Assignment overload
darray & darray::operator=(darray rhs){

	swap(rhs);
	return *this;

}


void darray::reset_capacity(int new_cap){

	darray temp(new_cap, *this);
	swap(temp);

}

/*
	int * temp_data = new int[new_cap];

	for(int i = 0; i < new_cap; ++i){
		if(i >= cap) {
			temp_data[i] = 0;
		}else{
			temp_data[i] = data[i];
		}
	}

	delete [] data;
	data = temp_data;
	cap = new_cap;
	*/






// destructor
darray::~darray() {
	delete [] data;
}


// subscript overload
int darray::operator[](int i) const{
	assert( 0 <= i && i < cap);
	return data[i];
}


// non-const subscript overload
int & darray::operator[](int i){
	assert( 0 <= i && i < cap);
	return data[i];
}

// Subscript overload
int operator[](int) const;

// Subscript overload (non-const)
int & operator[](int);

// Capacity
int darray::capacity() const{
	return cap;
}


std::ostream & operator<<(std::ostream & out, const darray & ar){
	for(int i = 0; i < ar.capacity(); ++i) {
		out << ar[i] << " ";
	}
	return out;
}



std::istream & operator>>(std::istream & in, const darray & ar){
	for(int i = 0; i <= ar.capacity(); ++i){
		in >> ar[i];
	}
	return in;
}




