#include <iostream>




/*
void string_fun(char ** cstring){
	
	*cstring = "foobar";

}
*/


int main(int argc, char * argv[]) {

	int * dynamic = new(std::nothrow) int[42];
	if(dynamic == nullptr){
		std::cout << "bad allocate\n";
		return 1;
	}

	dynamic[0] = 42;
	dynamic[1] = 123;
	*(dynamic + 2) = 444;

	std::cout << "dynamic[0]'s address' is " << &dynamic[0] << '\n';
	std::cout << "dynamic[0]: " << dynamic[0] << '\n';
	std::cout << "dynamic[1]'s address is " << &dynamic[1] << '\n';
	std::cout << "dynamic[1]: " << dynamic[1] << '\n';
	std::cout << "dynamic[2]'s address is " << &dynamic[2] << '\n';
	std::cout << "dynamic[2]: " << dynamic[2] << '\n';

	delete [] dynamic;



/*
	int x = 10;

	int * pointy = &x;

	std::cout << "x is: " << x << '\n';

	std::cout << "pointy points to: " << *pointy << '\n';

	std::cout << "pointy holds the value: " << pointy << " This is x's memory location" << '\n';

	if(true and true){
		std::cout << "condition was true" << '\n';
	}

	char * c = "foo";

	string_fun(&c);

	std::cout << "*c is: " << *c << '\n';

	

	*/

	return 0;


}