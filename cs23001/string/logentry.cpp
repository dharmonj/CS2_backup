/**
 * @file logentry.hpp
 *
 * @version 1.0
 * @date 3/14/2017
 * @author Donald Harmon II
 *
 * Implementation for a log_entry.
 *
 */

#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

/**
 * @accessor methods for date 
 */

// Gets private member day
String date_type::get_day() const{
	return day;
}

// Gets private member month
String date_type::get_month() const{
	return month;
}

// Gets private member year
int date_type::get_year() const{
	return year;
}


/**
 * @mutator methods for date 
 */

// set_day method sets day to input String
void date_type::set_day(String d){
	day = d;
}

// set_month method sets month to input String
void date_type::set_month(String m){
	month = m;
}

// set_year method converts input String to int and sets year
void date_type::set_year(String y){
	year = strToInt(y);
}


/**
 * @accessor methods for time
 */

// Gets private member hour
int time_type::get_hour() const{
	return hour;
}

// Gets private member minute
int time_type::get_minute() const{
	return minute;
}

// Gets private member second
int time_type::get_second() const{
	return second;
}


/**
 * @mutator methods for time
 */

// set_hour method converts input String to int and sets hour
void time_type::set_hour(String h){
	hour = strToInt(h);
}

// set_minute method converts input String to int and sets minute
void time_type::set_minute(String m){
	minute = strToInt(m);
}

// set_second method converts input String to int and sets second
void time_type::set_second(String s){
	second = strToInt(s);
}


/**
 *@friend output overload for date
 */

// << overload as a friend, for date_type ADT
std::ostream & operator<<(std::ostream & out, const date_type & rhs){
	out << "[" << rhs.day << "/" << rhs.month << "/" << rhs.year;
	return out;
}


/**
 *@friend output overload for time
 */

// << overload as a friend for time_type ADT
std::ostream & operator<<(std::ostream & out, const time_type & rhs){

	out << ":" << rhs.hour << ":";
	if(rhs.minute < 10){
		out << "0";
	} 
	out << rhs.minute << ":";
	if(rhs.second < 10){
		out << "0";
	}
	out << rhs.second;
	return out;
}


/**
 * @pre input String is assumed to be Apache CLF
 * @post log_entry object properly constructed, or empty (if missing info.)
 */

// log_entry String constructor
log_entry::log_entry(const String & s): log_entry() {
    
	// Split the input String on space (" ")
	std::vector<String> vec = s.split(' ');
	// If resulting vector is of valid size
	// Parse the vector into the member variables of log_entry
	// Result will be empty log_entry if size != 10 (invalid entry)
	if(vec.size() == 10){
		host = vec[0];
		date.set_day(vec[3].substr(1,2));
		date.set_month(vec[3].substr(4,3));
		date.set_year(vec[3].substr(8,4));
		time.set_hour(vec[3].substr(13,2));
		time.set_minute(vec[3].substr(16,2));
		time.set_second(vec[3].substr(19,2));
		String unFormReq = vec[5] + " " + vec[6] + " " + vec[7];
		request = unFormReq.substr(1, unFormReq.length() - 2);
		status = vec[8];
		number_of_bytes = strToInt(vec[9]);
		// Account for Apache CLF annotation for no byte info.
		if(vec[9] == "-"){
			number_of_bytes = 0;
		}
	}
}


/**
 * @pre istream is in usable state, reads from log file in Apache CLF
 * @post return a vector of properly constr. <log_entry>'s'
 */

// parse function reads in all log entries from "in" and stores them
// in a vector of log_entry ADT's, stores empty log_entry if invalid (size!=10)
std::vector<log_entry> parse(std::istream & in) {
   
	std::vector<log_entry> result;
	String entry;

	// While there are lines to get
	while(in){
		// Get them
		entry.get_line(in, entry);
		// If line isn't empty
		if(entry != ""){
			// Construct a log_entry and push it on to the vector
			result.push_back(log_entry(entry));
		}
	}
	return result;
}


/*
 *@accessor methods for log_entry
 */

// Get the number_of_bytes
int log_entry::get_bytes() const{
	return number_of_bytes;
}

// Get the host
String log_entry::get_host() const{
	return host;
}


/**
 * @pre rhs is a properly constructed log_entry
 * @post all members of rhs neatly output to ostream out
 */

// << overload for log_entry ADT outputs an entry in Apache CLF
std::ostream & operator<<(std::ostream & out, const log_entry & rhs){
	out << rhs.host << " - - " << rhs.date << rhs.time << " -0400] \"" << rhs.request << "\" " << rhs.status << " ";
	if(rhs.number_of_bytes == 0){
		out << "-" << '\n';
	} else {
		out << rhs.number_of_bytes << '\n';
	}
	return out;
}


/**
 * @pre entries full of properly constructed or empty log_entrys
 * @post all valid log_entrys output to ostream out, neatly, 1 per line
 */

// output_all function outputs all log_entrys in "entries" in Apache CLF
void output_all(std::ostream & out, const std::vector<log_entry> & entries) {
	for(const auto& entry : entries){
		if(entry.get_host() != ""){
			out << entry;
		}
	}
}


/**
 * @pre entries full of properly constructed or empty log_entrys
 * @post host output to ostream out for all valid log_entrys, 1 per line
 */

// by_host function outputs all hosts, 1 per line, from "entries"
void by_host(std::ostream & out, const std::vector<log_entry> & entries) {
	for(const auto& entry : entries){
		if(entry.get_host() != ""){
			out << entry.get_host() << '\n';
		}
	}
}


/**
 * @pre entries full of properly constructed or empty log_entry's
 * @post total of all bytes output to ostream out
 */

// byte_count function outputs total bytes of all log_entrys in "entries"
int byte_count(const std::vector<log_entry> & entries) {
    
	int total = 0;
	for(const auto& entry : entries){
		total += entry.get_bytes();
	}

	return total;
}

