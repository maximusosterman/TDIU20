#ifndef TIME_H
#define TIME_H

#include <string>

class Time {

public:
    Time();
    Time(int hour, int minute, int second);
    Time(std::string const& time_string);
    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    
    bool is_am() const;
    std::string to_string(bool twentyfour_hour_format = true) const&;

private:
    int hour;
    int minute;
    int second;

    void check_valid_clock_range(int hour, int minute, int second);
    void format_12h(std::string& hour_str, std::string& am_pm) const; 

};

#endif