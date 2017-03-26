#include <string>
#include <iostream>
#include <fstream>
#include <ostream>


// FUNCTION PROTOTYPES
void get_word(std::ifstream&, std::string &);
void get_line(std::ifstream&, std::string &);


int main(int argc, char * argv[]){

  // Check for correct number of arguments
	if(argc != 4){
		std::cerr << "Incorrect number of arguments, exiting." << '\n';
		exit(1);
	}
  // Check that the user has chosen a valid operation
  if((argv[1][0]-'0')!=1 && (argv[1][0]-'0')!=2){
    std::cerr << "Please choose a valid operation, 1 for get_word, 2 for get_line. Exiting." << '\n';
    exit(1);
  }
  // Check that the user has chosen a valid input file
	std::ifstream in(argv[2]);    		  // Define stream for input
  if(!in) {                           // Make sure it opened correctly.
      std::cerr << "Could not open " << argv[2] << " exiting." << std::endl;
      exit(1);
  }
  // Check that the user has chosen a valid output file
  std::ofstream out(argv[3]);         // Define stream for output
  if(!out) {                          // Make sure it opened correctly.
    std::cerr << "Could not open " << argv[3] << " exiting." << std::endl;
  }

  
  // Perform desired operation
  std::string str;

  // USER CHOOSES GET_WORD
  if((argv[1][0]-'0') == 1){

    int count = 0;
  	get_word(in, str);
    char form;

    while(in){
      out << str;
      in.get(form);
      out << form;
      get_word(in, str);
      count++;
    }

    out << "Number of words: " << count << '\n';

  }

  // USER CHOOSES GET_LINE
  if((argv[1][0]-'0') == 2){
    get_line(in, str);

    // Make sure single line files are processed correctly
    if(!in){
      out << str;
    }
 
    // Process file
    while(in){
      out << str;
      get_line(in, str);
    }

    // Make sure last line is processed correctly
    if(!in){
      out << str;
    }
    
  }

  in.close();
  out.close();

} 
// END MAIN


// FUNCTION DEFINITIONS

// Get a single word from the file
void get_word(std::ifstream & in, std::string & str){
	in >> str;
}


// Get a line from the file
void get_line(std::ifstream & in, std::string & str){
  str = "";
  char ch;
  // While there are characters, and on the same line, add them to string
  while(in.get(ch)&&ch!='\n'){
    str += ch;
  }
  // If new line character found, add it in, if in.get() failed, don't
  if(ch=='\n'){
    str+=ch;
  }
}





