/**
 * Donald Harmon
 * String Implementation File
 * CS23001
 */
#include <iostream>
#include <cassert>
#include "string.hpp"

 // constructor: empty string, String('x'), and String("abcd")

		// Default constructor (empty string) TESTED
    String::String(){
    	str[0] = 0;
    }


    // Char Constructor (single character) TESTED
    String::String(char ch){
    	str[0] = ch;
    	str[1] = 0;
    }


    // Char [] constructor (character array) TESTED
    String::String(const char * chars){

    	int i = 0;

    	// Subtask stores char[] in calling String, as long as there is room
    	while(chars[i] != 0){
    		str[i] = chars[i];
    		++i;
    		if(i >= capacity()){
    			break;
    		}
    	}
    	str[i] = 0;
    }


    // subscript: accessor/modifier TESTED
    char & String::operator[](int i){
    	assert(i >= 0);
    	assert(i < length());
    	return str[i];
    }


    // subscript: accessor TESTED
    char String::operator[](int i) const{
    	assert(i >= 0);
    	assert(i < length());
    	return str[i];
    }


    // max chars that can be stored (not including null terminator) TESTED
    int String::capacity() const{
    	return STRING_SIZE - 1;
    }


    // number of char in string TESTED
    int String::length() const{
    	int i = 0;
    	while(str[i] != 0){
    		++i;
    	}
    	return i;
    }


    // concatenation + overload
    String String::operator+(const String & rhs) const{

    	// Subtask stores *this in result, finds length
    	String result(str);
    	int offset = length();
    	int i = 0;

    	// Subtask stores rhs in result after *this 
    	while(rhs.str[i] != 0){
    		if((offset + i) >= capacity()){break;}
    		result.str[offset + i] = rhs.str[i];
    		++i;
    	}

    	// Store null terminator and return result
    	result.str[offset + i] = 0;
    	return result;
    }


    // concatenation += operator overload TESTED
    String & String::operator+=(String rhs){

    	int offset = length();
    	int i = 0;

    	// Subtask stores rhs in calling String, after *this
    	while(rhs.str[i] != 0){
    		if((offset + i) >= capacity()){break;}
    		str[offset + i] = rhs.str[i];
    		++i;
    	}

    	// Store null terminator and return *this
    	str[offset + i] = 0;
    	return *this;
    }


    // relational methods
    // comparison operator overload TESTED
    bool String::operator==(const String & rhs) const{

    	int i = 0;

    	// Subtask compares two Strings, returns true if match, false if not
    	while(str[i] != 0 && str[i] == rhs.str[i]){
    		++i;
    	}
    	return str[i] == rhs.str[i];
    }


    // less than operator overload TESTED
    bool String::operator<(const String & rhs) const{

    	int i = 0;

    	// Subtask compares two Strings
    	while(str[i] != 0 && rhs.str[i] != 0 && str[i] == rhs.str[i]){
    		++i;
    	}

    	// returns true if *this < rhs, false otherwise
    	return str[i] < rhs.str[i];
    }


    // i/o
    // input operator overload
    std::istream & operator>>(std::istream & in, String & rhs){

    	// Reads in one word from input stream, return the stream
    	in >> rhs.str;
    	return in;
    }


    // output operator overload
    std::ostream & operator<<(std::ostream & out, const String & rhs){

    	// Output String to output stream
    	out << rhs.str;
    	return out;
    }


		// free functios for concatenation and relational
		// concatenation overload for char array lhs
		String operator+(const char * left, const String & rhs){

			// Adds char[] to String
			String lhs(left);
			String result = lhs + rhs;

			// Return the new String
			return result;
		}


		// concatenation overload for single char lhs
		String operator+(char left, const String & rhs){

			// Adds single char to String
			String lhs(left);
			String result = lhs + rhs;

			// Return the new String
			return result;
		}


		// comparison overload for char array lhs TESTED
		bool operator==(const char * left, const String & rhs){

			// Construct char[] into String
			String lhs(left);

			// Return true if match, false otherwise
			return (lhs == rhs);
		}


		//comparison overload for single char lhs TESTED
		bool operator==(char left, const String & rhs){

			// Construct char into String 
			String lhs(left);

			// Return true if match, false otherwise
			return (lhs == rhs);
		}

		
		// less than overload for char array lhs TESTED
		bool operator<(const char * left, const String & rhs){

			// Construct char[] into String
			String lhs(left);

			// Return true if char[] < String, false otherwise
			return (lhs < rhs);
		}

		
		// less than overload for single char lhs TESTED
		bool operator<(char left, const String & rhs){

			// Construct char into String
			String lhs(left);

			// Return true if char < String, false otherwise
			return (lhs < rhs);
		}

		
		// less than / equal to overload for String lhs TESTED
		bool operator<=(const String & lhs, const String & rhs){

			// Return true if lhs String is less than or equal to rhs String
			return (lhs < rhs || lhs == rhs);
		}

		
		// not equal to overload for String lhs TESTED
		bool operator!=(const String & lhs, const String & rhs){

			// Return true if lhs String is not equal to rhs String, false if not
			return !(lhs==rhs);
		}

		
		// greater than / equal to overload for String lhs TESTED
		bool operator>=(const String & lhs, const String & rhs){

			// Return true if lhs String greater than or equal to rhs String
			return !(lhs<rhs);
		}

		
		// greater than overload for String lhs TESTED
		bool operator>(const String & lhs, const String & rhs){

			// Return true if lhs String is greater than rhs String
			return !(lhs < rhs || lhs == rhs);
		}

		



    // tests if string is null terminated, added by me for testing purposes
    bool String::is_null_terminated(){
    	for(int i = 0; i < capacity(); ++i){
    		if(str[i] == 0){
    			std::cout << "It's null terminated!" << '\n';
    			std::cout << "str[" << i << "] is the null terminator" << '\n';
    			return true;
    		}
    	}
    	std::cout << "no null terminator!!!";
    	return false;
    }
