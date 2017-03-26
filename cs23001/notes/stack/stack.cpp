#include <iostream>
#include <cstdlib>
#include <cassert>
#include "stack.hpp"


int main(int argc, char * argv[]){

	stack<int> int_stack;
	int_stack.push(42);
	int_stack.push(21);
	int_stack.push(7);


	std::cout << int_stack.top() << '\n';
	int_stack.pop();

	std::cout << int_stack.top() << '\n';
	int_stack.pop();

	std::cout << int_stack.top() << '\n';
	int_stack.pop();

	stack<std::string> str_stack;

	return 0;

}



