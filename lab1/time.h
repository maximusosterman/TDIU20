#ifndef TIME_H
#define TIME_H

#include <string>

class Time {

public:
    Time(int hour, int minute, int second);
    Time(std::string const& time_string = "00:00:00");

    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    
    bool is_am() const;
    std::string to_string(bool twentyfour_hour_format = true) const&;

    bool operator==(const Time& rhs) const;
    bool operator!=(const Time& rhs) const;

    bool operator<(const Time& rhs) const;
    bool operator<=(const Time& rhs) const;

    bool operator>(const Time& rhs) const;
    bool operator>=(const Time& rhs) const;

    Time operator++();
    Time operator++(int);

    Time operator--();
    Time operator--(int);

private:
    int hour;
    int minute;
    int second;

    //helpers
    void check_valid_clock_range(int hour, int minute, int second) const;
    void format_12h(std::string& hour_str, std::string& am_pm) const; 
    int get_total_seconds() const;

};

std::ostream& operator<<(std::ostream& os, const Time& time);

#endif