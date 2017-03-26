/**
 * Donald Harmon
 * String Implementation File - Milestone 2 - Had fun, good project
 * CS23001
 */
#include <iostream>
#include <cassert>
#include <vector>
#include "string.hpp"


// PRIVATE METHODS
// Private int constructor
String::String(int cap){
    string_size = cap + 1;

    // Ensure string_size is not <= 0
    assert(string_size>0);
    // Allocate desired space
    str = new char[string_size];
    // Insert null terminator
    str[0] = '\0';
}


// Private constructor for String of cap capacity, loaded with char[]
String::String(int cap, const char * chars){
    string_size = cap + 1;

    // Allocate enough space for chars and null terminator
    str = new char[string_size];
    int i = 0;

    // While there are characters and space
    while(chars[i] != '\0' && i < cap){
        // Read in the values from char[], count them
        str[i] = chars[i];
        ++i;
    }

    // Insert null terminator
    str[i] = '\0';
}


// Reset_capacity method (private)
void String::reset_capacity(int new_cap){
    // Create temp string with correct new capacity and original values
    String temp(new_cap, str);
    // Swap with original String
    swap(temp);
}


// PUBLIC METHODS
// Default constructor, calls private empty String constructor
String::String(): String(0){}


// Char constructor, calls private empty String constructor
String::String(char ch): String(1) {
    // Read in the char
    str[0] = ch;
    // Insert null terminator
    str[1] = '\0';
}


// Char[] constructor
String::String(const char * chars){
    int pos = 0;

    // While there are characters
    while(chars[pos] != '\0'){
        // Count them
        ++pos;
    }

    // Allocate enough space for characters and null terminator
    str = new char[pos + 1];

    // Read in the values from char[]
    for(int i = 0; i < pos; ++i){
        str[i] = chars[i];
    }

    // Insert null terminator, assign string_size
    str[pos] = '\0';
    string_size = pos + 1;   
}
    

// Copy constructor
String::String(const String & rhs) : String(rhs.capacity()) {
    // Construct array with values from rhs
    for(int i = 0; rhs.str[i] != '\0'; ++i){
        str[i] = rhs.str[i];
    }
    // Insert null terminator
    str[capacity()] = '\0';
}


// Destructor
String::~String(){
    // Free memory when object goes out of scope
    delete [] str;
}


// Constant time swap method
void String::swap(String & rhs){

    // Swap the string sizes
    int temp_string_size = string_size;
    string_size = rhs.string_size;
    rhs.string_size = temp_string_size;

    // Swap the pointers that allow char array access
    char * temp_str = str;
    str = rhs.str;
    rhs.str = temp_str;
}    


// Assignment overload
String & String::operator=(String rhs){

    swap(rhs);
    
    // Return calling String
    return *this;
}


// Subscript: accessor/modifier
char & String::operator[](int i){
    assert(i < capacity() && i > -1);
    // Return char at position requested
    return str[i];
}


// Subscript: accessor
char String::operator[](int i) const{
    assert(i < capacity() && i > -1);
    // Return char at position requested
    return str[i];
}


// Capacity method
int String::capacity() const {
    // Return max capacity of String object
    return string_size - 1;
}


// Length method
int String::length() const {
    int i = 0;

    // While there are characters in array, add to count
    while(str[i] != '\0'){
        ++i;
    }
    // Return count of characters
    return i;
}


// Assignment operator overload
String String::operator+(const String & rhs) const{


     // Find end of caller
    int offset = length();
    // Construct new string with enough space and calling array
    String result(offset+rhs.length(), str);
   


    int i = 0;
    // Subtask moves rhs char array to result after end of caller
    while(rhs.str[i] != '\0'){
        result.str[offset+i] = rhs.str[i]; 
        ++i;
    }

    // Insert null terminator and return result String
    result.str[offset+i] = '\0';
    return result;
}


// Compound assignment/addition operator overload
String & String::operator+=(String rhs){
    // Find end of caller
    int offset = length();
    // Set the new cap of calling String
    int new_cap = offset + rhs.length();
    reset_capacity(new_cap);
    
    // Subtask moves rhs char array to caller after end
    for(int i = 0; i < rhs.length(); ++i){
        str[offset+i] = rhs.str[i];
    }

    // Insert null terminator and return calling object
    str[capacity()] = '\0';
    return *this;
}


// Comparison operator overload
bool String::operator==(const String & rhs) const{
    int i = 0;
    // Subtask compares two Strings
    while(str[i] != 0 && str[i] == rhs.str[i]){
        ++i;
    }
    // Returns true if match, false if not
    return str[i] == rhs.str[i];
}


// Less than operator overload
bool String::operator<(const String & rhs) const{ 
    int i = 0;
    // Subtask compares two Strings lexigraphically
    while(str[i] != 0 && rhs.str[i] != 0 && str[i] == rhs.str[i]){
        ++i;
    }
    // Returns true if *this < rhs, false otherwise
    return str[i] < rhs.str[i];
}


// Output operator overload as a friend
std::ostream& operator<<(std::ostream & out, const String & rhs){
    // Output String to output stream
    out << rhs.str;
    return out;
}


// Input operator overload as friend
std::istream& operator>>(std::istream & in, String & rhs){
    
    // Set to empty String
    rhs = "";
    // Read in one char, skipping whitespace
    char ch;
    if(!(in >> ch)) return in;
    rhs += ch;
    
    // While not whitespace and not end of file
    while(in.get(ch) && ch!=' '&&ch!='\n'&&ch!='\t'&&ch!='\r'){
        // Add char to rhs String
        rhs += ch; 
    }

    // Return the input stream
    return in;
}


// free functios for concatenation and relational
String operator+(const char * chars, const String & rhs){

    // Convert chars to String
    String lhs(chars);
    // Concatenate Strings
    String result = lhs + rhs;
    // Return the new String
    return result;
}


// Addition operator overload
String operator+(char ch, const String & rhs){

    // Convert ch to String for concatenation
    String lhs(ch);
    // Concatenate Strings
    String result = lhs + rhs;
    // Return the new String
    return result;

}


// Comparison free operator overload
bool operator==(const char * left, const String & rhs){
    // Convert char[] to String for comparison
    String lhs(left);
    // Return true if lhs is equal to rhs
    return (lhs == rhs);
}


// Comparison free operator overload
bool operator==(char ch, const String & rhs){
    // Convert char to String for comparison
    String lhs(ch);
    // Return true if lhs is equal to rhs
    return (lhs == rhs);
}


// Less than free operator overload
bool operator<(const char * chars, const String & rhs){
    // Convert char[] to String for less than comparison
    String lhs(chars);
    // Return true if lhs is less than rhs
    return (lhs < rhs);
}


// Less than free operator overload
bool operator<(char ch, const String & rhs){
    // Convert char to String for less than comparison
    String lhs(ch);
    // Return true if lhs is less than rhs
    return (lhs < rhs);
}


// Less than or equal to free operator overload
bool operator<=(const String & lhs, const String & rhs){
    // Return true if lhs String is less than or equal to rhs String
    return (lhs < rhs || lhs == rhs);
}


// Not equal to free operator overload
bool operator!=(const String & lhs, const String & rhs){
    // Return true if lhs String is not equal to rhs String
    return !(lhs==rhs);
}


// Greater than or equal to free operator overload
bool operator>=(const String & lhs, const String & rhs){
    // Return true if lhs String greater than or equal to rhs String
    return !(lhs<rhs);
}


// Greater than free operator overload
bool operator>(const String & lhs, const String & rhs){
    // Return true if lhs String is greater than rhs String
    return !(lhs < rhs || lhs == rhs);
}


// Substring method (returns part of a String)
String String::substr(int start_pos, int count) const{
    // Return empty String if count <= 0 or start >= length
    if(count <= 0 || start_pos >= length()){
        String empty;
        return empty;
    }
    // Ensure i and start_pos are >= 0
    int i = 0;
    if(start_pos > 0){
        i = start_pos;
    }else{
        start_pos = 0;
    }
    
    // Allocate enough space for new String + '\0'
    char chars[count + 1];
    // Load char[] with desired substring, or until end. W/E comes first
    while(str[i] != '\0' && i - start_pos < count){
        chars[i - start_pos] = str[i];
        ++i;
    }

    // Null terminate char[]
    chars[i - start_pos] = '\0';
    // Construct substring from char[] and return
    String sub(chars);
    return sub;
}


// Find char method (returns index of char if found, -1 if not)
int String::find(char ch, int start_pos) const {
    // Guard clause, if invalid start_pos, return not found
    if(start_pos >= length() || start_pos < 0){return -1;}

    int i = start_pos;

    // While there are valid char's, search through them (main loop)
    while(str[i] != '\0'){
        // Return index if ch is found
        if(str[i] == ch){
            return i;
        }
        ++i;
    }
    // Return not found if ch is not in calling String
    return -1;
}


// Find String method (returns index of start of String if found, -1 if not)
int String::find(const String & s, int start_pos) const{
    // Guard clause, if invalid start_pos, return not found
    if(start_pos > length() || start_pos < 0){return -1;}
    // Guard clause, to conform to STL 
    if(s == ""){return start_pos;}

    int s_len = s.length();
    int len = length();
    int i = start_pos;

    // While there are characters (main loop)
    while(str[i] != '\0'){
        // If first char is found
        if(str[i] == s.str[0]){
            // See if there is room to find the rest of s, if not return -1
            if(s_len > len - i){break;}
            // There is enough room for the rest, examine
            for(int j = 0; j < s_len; ++j){
                // If rest of chars don't match, break/look for 1st char again
                if(str[i+j] != s.str[j]){break;}
                // If last char matches, we have found s, return index
                if(j==s_len-1){return i;}
            }
        }
        ++i;
    }

    // If the String s was not found in the caller, return -1
    return -1;
}


// Split method splits calling string by delimiter provided
std::vector<String> String::split(char delim) const {
    // Index (start point)
    int i = 0;

    std::vector<String> result;

    // Find first delimiter, if any
    int i_of_del = find(delim, i);

    // While there is a delimiter
    while(i_of_del > -1){
        // Get the characters in between delimiter and i, add to vector
        result.push_back(substr(i, i_of_del - i));
        // Reset i to begin after delimiter for next word
        i = i_of_del + 1;
        // Find the next delimiter
        i_of_del = find(delim, i);
    }

    // Ensure single word, or empty string only is added to vector, and return
    result.push_back(substr(i, length() - i));

    return result;
}


// Tests if string is null terminated, added by me for testing purposes
bool String::is_null_terminated() const {
    for(int i = 0; i <= length(); ++i){
        if(str[i] == 0){
            std::cout << "It's null terminated!" << '\n';
            std::cout << "str[" << i << "] is the null terminator" << '\n';
            return true;
        }
    }
    std::cout << "no null terminator!!!";
    return false;
}


// Get line method to help with processing log_entry's
void String::get_line(std::istream & in, String & rhs){

    // Set rhs to empty String
    rhs = "";
    // Read in one char
    char ch;
    if(!(in >> ch)) return;
    rhs += ch;
    
    // While not end of line or eof
    while(in.get(ch) &&ch!='\n'){
        // Add char to rhs String
        rhs += ch; 
    }

}


// Convert input String to integer
int strToInt(String str){

    int result = 0;
    int i = 0;
    while(i < str.length()){
        result *= 10;
        result += str[i] - '0';
        ++i;
    }

    return result;
}