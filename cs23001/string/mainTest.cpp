#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ostream>
#include <cassert>
#include <vector>
#include "string.hpp"
#include "logentry.hpp"


int main(){

	std::ifstream in("log_2_small.txt");    // Define stream for input
  if(!in) {                           // Make sure it opened correctly.
      std::cerr << "Could not open log file, exiting." << std::endl;
      exit(1);
  }
  
 
 
 	std::vector<log_entry> entries = parse(in);


 	std::cout << byte_count(entries) << '\n';

 	by_host(std::cout, entries);

 	output_all(std::cout, entries);

	in.close();



	return 0;
}


