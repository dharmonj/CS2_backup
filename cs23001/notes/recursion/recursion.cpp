#include <iostream>
#include <string>
// RECURSION - example file
// Recursion - 2 main parts recursive part and base case(stopping point for recursion)

// Stack frames
	// local variables, parameters, return address

int factorial(int); // Regular recursion (builds on stack)
int sum(int);
int tenToIth(int);
int charAtoInt(char * chars); // Convert char[] to int

int main(int argc, char * argv[]){



	if(argc > 2 || argc < 2){
		std::cout << "too many or too few arguments" << '\n';
		exit(1);
	}

	int passedInt = charAtoInt(argv[1]);

	std::cout << "number is: " << passedInt << '\n';

	std::cout << "factorial is: " << factorial(passedInt) << '\n';

	std::cout << "sum of it and its preceding values: " << sum(passedInt) << '\n';


	
	std::cout << "thanks for using the factorial and sum program!" << '\n';

}



int factorial(int i){

	if(i == 0) return 1;

	return i * factorial(i-1);

}


int sum(int num){

	if(num == 1) return 1;

	return num + sum(num - 1);

}


int tenToIth(int power){

	int result = 1;
	for(int i= 0; i < power; ++i){

		result = result * 10;
	}

	return result;
}



int charAtoInt(char * chars){

	int result = 0;
	int i = 0;
	while(chars[i] != '\0'){
		result *= 10;
		result += chars[i] - '0';
		++i;
	}

	

	return result;


}