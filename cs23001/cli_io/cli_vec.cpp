#include <iostream>
#include <vector>
#include <algorithm> //For sort()

/*
  Take a series of numbers from the command line and find:
  * MIN value
  * MAX value
  * sorted order
*/
int main(int argc, char* argv[]) {  

  if (argc == 1) {
    std::cerr << argv[0] << ": invalid number of arguments\n";
    std::cerr << "Example usage:\n" << "./num 12 -5 45 -2 22 1234 -500\n";
    return 1;
  }

  std::vector<int> numbers;
  
  for (int i = 1; i < argc; ++i) {
    
    int digit_pos = 0;
    int neg = 1;
    
    if (argv[i][digit_pos] == '-') {
      ++digit_pos;
      neg *= -1;
    }
    
    int value = 0;
    while (argv[i][digit_pos] != '\0'){ 
      value *= 10;
      value += argv[i][digit_pos] - '0';
      ++digit_pos;
    }

    numbers.push_back(value*neg);
  }

  std::sort(numbers.begin(), numbers.end());
  
  std::cout << "MIN: " << numbers.front() << "\n";
  std::cout << "MAX: " << numbers.back() << "\n\n";

  std::cout << "SORTED:\n";
  for (size_t i = 0; i < numbers.size(); ++i) {
    std::cout << numbers[i];
    if ( i != (numbers.size() - 1)){
      std::cout << ", ";
    }
    else {
      std::cout << "\n";   
    }
  }

  return 0;
}
