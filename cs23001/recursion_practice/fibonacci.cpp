/* Lab 8 - Recursion
 * Donald Harmon II
 * 3/9/17
 */
// Functions find the nth fibonacci number
// Base Cases n == 0  return 0
//           n == 1  return 1
// Recurrence relation f(n) = f(n-2) + f(n-1)

#include <iostream>

// FUNCTION PROTOTYPES
	// Conver char[] to int
	int charAtoInt(char *);
	// Regular Recursion
	unsigned int fibbo(unsigned int);
	// Tail End Recursion
	unsigned int fibbo_tr(unsigned int, unsigned int left, unsigned int right);
//--------------------------------------------------------------------------
// BEGIN MAIN
int main(int argc, char * argv[]){

// Check for correct number of arguments
	if(argc!=2){
		std::cerr << "Please input the correct number of arguments, exiting" << '\n';
		exit(1);
	}


	int input = charAtoInt(argv[1]);

// Check input validity (negative)
	if(input <= 0){
		std::cerr << "Please input a valid number (greater than 0), exiting" << '\n';
		exit(1);
	}
// Check input validity (more than max)
	if(input >= 170){
		std::cerr << "Please print less than 170 values.\n" << "Unsigned integer type causes inaccuracies when printing > 169 values\n" << "Exiting..." << '\n';
		exit(1);
	}

// User chooses to print using Regular Recursion, Tail End, or Both
	int choice = 0;
	while(choice != 1 && choice != 2 && choice != 3){
		// Ask user to choose recursion type
		std::cout << "How would you like to print fibonacci sequence?" << '\n' << "Regular recursion(1), tail end recursion(2), or both(3)" << '\n';
		std::cin >> choice;

		// Invalid choice
		if(choice != 1 && choice != 2 && choice != 3){
			std::cout << "Please enter a valid number (1 || 2 || 3)" << '\n';
		}
	}
// -------------------------------------------------------------------------

// Perform desired action

	// REGULAR
	if(choice == 1){
		std::cout << "\n Fibbonacci Sequence\n" << "----------------------\n"; 
		for(int i = 0; i < input; ++i){
			if(i < 9)std::cout << " ";
			std::cout << i + 1 << ": " << fibbo(i) << '\n';
		}
		std::cout << std::endl;
	// TAIL END
	}else if(choice == 2){
		std::cout << "\n Fibbonacci Sequence\n" << "----------------------\n"; 
		for(int i = 0; i < input; ++i){
			if(i < 9)std::cout << " ";
			std::cout << i + 1 << ": " << fibbo_tr(i, 0, 1) << '\n';
		}
		std::cout << std::endl;
	}else{
	// BOTH
		std::cout << "\n Regular Recursion\n" << "---------------------\n";
		for(int i = 0; i < input; ++i){
			std::cout << fibbo(i) << ' ';
		}
		std::cout << "\n\n Tail End Recursion\n" << "----------------------\n";
		for(int i = 0; i < input; ++i){
			std::cout << fibbo_tr(i, 0, 1) << ' ';
		}
		std::cout << "\n\n";
	}
// -------------------------------------------------------------------------

// Print Goodbye!
	std::cout << "Thanks for using the Fibonacci Sequence Printer, goodbye!" << "\n\n";
//--------------------------------------------------------------------------
	return 0;
}
// END OF MAIN FUNCTION


// FUNCTION DEFINITIONS
	// Regular Recursion
	unsigned int fibbo(unsigned int n){
		if(n==0||n==1){
			return n;
		}

		return fibbo(n-1) + fibbo(n-2);
	}

	// Tail End Recursion
	unsigned int fibbo_tr(unsigned int n, unsigned int left, unsigned int right){
		if(n==0)return left; // BaseCase
		if(n==1)return right;// BaseCase

		return fibbo_tr(n-1, right, left+right);
	}

	// Convert input char[] to integer
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
//--------------------------------------------------------------------------