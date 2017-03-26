#ifndef CS2_LOGENTRY_HPP
#define CS2_LOGENTRY_HPP

/**
 * @file logentry.hpp
 *
 * @version 1.0
 * @date
 * @author
 *
 *  Class definition for a log entry.
 *
 */

#include <iostream>
#include <vector>

#include "string.hpp"

/** date_type class */
class date_type {
public:
    date_type() : year(0) {};
    String get_day() const;
    String get_month() const;
    int get_year() const;
    void set_day(String);
    void set_month(String);
    void set_year(String);
    friend std::ostream & operator<<(std::ostream &, const date_type &);
private:
    String day, month;
    int    year;
};

/** time_type class */
class time_type {
public:
    time_type() : hour(0), minute(0), second(0) {};
    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    void set_hour(String);
    void set_minute(String);
    void set_second(String);
    friend std::ostream & operator<<(std::ostream &, const time_type &);
private:
    int hour, minute, second;
};


/** log_entry class */
class log_entry {
public:
    log_entry(): number_of_bytes(0){};
    log_entry(const String &);
    friend std::ostream & operator<<(std::ostream &, const log_entry &);
    int get_bytes() const;
    String get_host() const;

private:
    String host;
    date_type date;
    time_type time;
    String request;
    String status;
    int    number_of_bytes;
};


// free functions
std::vector<log_entry>  parse       (std::istream &);
void                    output_all  (std::ostream &, const std::vector<log_entry> &);
void                    by_host     (std::ostream &, const std::vector<log_entry> &);
int                     byte_count  (const std::vector<log_entry> &);


#endif
