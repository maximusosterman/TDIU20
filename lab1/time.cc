#include "time.h"
#include <stdexcept>
#include <string>  

Time::Time() : hour {}, minute {}, second {} {}; 

Time::Time(int hour, int minute, int second) 
    : hour {hour}, minute {minute}, second {second} {
        check_valid_clock_range(hour, minute, second);
    }

Time::Time(std::string const& time_string)
    : hour      {std::stoi(time_string.substr(0, 2))},  
      minute    {std::stoi(time_string.substr(3, 2))},
      second    {std::stoi(time_string.substr(6, 2))} {

        check_valid_clock_range(hour, minute, second);
    }

int Time::get_hour() const {
    return hour;
}

int Time::get_minute() const {
    return minute;
}

int Time::get_second() const {
    return second;
}

void Time::check_valid_clock_range(int hour, int minute, int second) const {
    if (second > 59) throw std::logic_error("Second out of range!");
    if (minute > 59) throw std::logic_error("Minutes out of range!");
    if (hour > 23) throw std::logic_error("Hours out of range!");
}

bool Time::is_am() const {
    return hour < 12;
}

std::string Time::to_string(bool twentyfour_hour_format) const& {

    std::string hour_str {};
    std::string minute_str {};
    std::string second_str {};
    std::string am_pm {};

    if (hour < 10) {
        hour_str = "0" + std::to_string(hour);
    } else {
        hour_str = std::to_string(hour);
    }

    if (minute < 10) {
        minute_str = "0" + std::to_string(minute);
    } else {
        minute_str = std::to_string(minute);
    }
    
    if (second < 10) {
        second_str = "0" + std::to_string(second);
    } else {
        second_str = std::to_string(second);
    }

    if (!twentyfour_hour_format) Time::format_12h(hour_str, am_pm);

    return hour_str + ":" + minute_str + ":" + second_str + am_pm;
}

void Time::format_12h(std::string& hour_str, std::string& am_pm) const {
    if (Time::is_am()) {
        am_pm = "am";
    } else {
        am_pm = "pm";
        hour_str = std::to_string(hour - 12);
        if (std::stoi(hour_str) < 10) {
            hour_str = "0" + hour_str;
        };
    }
    if (hour == 0 || hour == 12) {
        hour_str = "12";
    }
}

int Time::get_value() const {
    return hour * 3600 + minute * 60 + second;
};

bool Time::operator==(const Time& rhs) const {
    return Time::get_value() == rhs.get_value();
};

bool Time::operator!=(const Time& rhs) const {
    return !(*this == rhs);
};

bool Time::operator<(const Time& rhs) const {
    return Time::get_value() < rhs.get_value();
};

bool Time::operator<=(const Time& rhs) const {
    return Time::get_value() <= rhs.get_value();
};

bool Time::operator>(const Time& rhs) const {
    return Time::get_value() > rhs.get_value();
};

bool Time::operator>=(const Time& rhs) const {
    return Time::get_value() >= rhs.get_value();
};