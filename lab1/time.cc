#include "time.h"
#include <stdexcept>
#include <string>  

Time::Time() : hour {}, minute {}, second {} {}; 

Time::Time(int hour, int minute, int second) 
    : hour {hour}, minute {minute}, second {second} {
        check_valid_clock_range(hour, minute, second);
    };

// Time::Time(std::string const& time_string) {
    

// }


int Time::get_hour() const {
    return hour;
}

int Time::get_minute() const {
    return minute;
}

int Time::get_second() const {
    return second;
}

void Time::check_valid_clock_range(int hour, int minute, int second) {
    if (second > 59) throw std::logic_error("Second out of range!");
    if (minute > 59) throw std::logic_error("Minutes out of range!");
    if (hour > 23) throw std::logic_error("Hours out of range!");
}