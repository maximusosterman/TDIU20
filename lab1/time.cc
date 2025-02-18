#include "time.hpp"
#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>

// OBS bonus rättas inte i framtiden.
// Komplettering (bonus): Att implementera operator+ m.h.a operator++ är extremt ineffektivt.
//   Implementera dem åt andra hållet istället. Gäller även operator-

Time::Time(int hour, int minute, int second)
    : hour {hour}, minute {minute}, second {second} {
        check_valid_clock_range(hour, minute, second);
    }

Time::Time(std::string const& time_string) {

    int h, m, s;
    char c1, c2;
    std::istringstream ss(time_string);

    if (!(ss >> h >> c1 >> m >> c2 >> s) || c1 != ':' || c2 != ':') {
        throw std::logic_error("Invalid time format!");
    }
    hour = h;
    minute = m;
    second = s;

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

void Time::set_hour(int hour_in) {
    hour = hour_in;
    while (hour > 23) {
        hour -= 24;
    }
}

void Time::set_minute(int minute_in) {
    minute = minute_in;
    while (minute > 59) {
        minute -= 60;
        hour += 1;
        if (hour > 23) {
            hour -= 24;
        }
    }
}

void Time::set_second(int second_in) {
    second = second_in;
    while (second > 59) {
        second -= 60;
        minute += 1;
        if (minute > 59) {
            hour += 1;
            minute -= 60;
        }
        if (hour > 23) {
            hour -= 24;
        }
    }
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
        if ((hour - 12) < 10) {
            hour_str = "0" + hour_str;
        };
    }
    if (hour == 0 || hour == 12) {
        hour_str = "12";
    }
}

int Time::get_total_seconds() const {
    return hour * 3600 + minute * 60 + second;
};

bool Time::operator==(const Time& rhs) const {
    return Time::get_total_seconds() == rhs.get_total_seconds();
};

bool Time::operator!=(const Time& rhs) const {
    return !(*this == rhs);
};

bool Time::operator<(const Time& rhs) const {
    return Time::get_total_seconds() < rhs.get_total_seconds();
};

bool Time::operator<=(const Time& rhs) const {
    return Time::get_total_seconds() <= rhs.get_total_seconds();
};

bool Time::operator>(const Time& rhs) const {
    return Time::get_total_seconds() > rhs.get_total_seconds();
};

bool Time::operator>=(const Time& rhs) const {
    return Time::get_total_seconds() >= rhs.get_total_seconds();
}

Time& Time::operator++() {

    *this = *this + 1;

    return *this;
}

Time operator+(const Time& lhs, int seconds) {
    Time temp {lhs}; // Copy the original object
    int current_seconds = lhs.get_second();

    temp.set_second(current_seconds + seconds);

    return temp;
}

Time operator+(int seconds, const Time& rhs) {
    return rhs + seconds;
}

Time Time::operator++(int) {
    Time temp {*this};
    ++(*this);
    return temp;
}

Time& Time::operator--() {
    --second;
    if (second == -1) {
        second = 59;
        --minute;
        if (minute == -1) {
            minute = 59;
            --hour;
            if (hour == -1) {
                hour = 23;
            }
        }
    }
    return *this;
}

Time Time::operator--(int) {
    Time temp {*this};
    --(*this);
    return temp;
}

Time Time::operator-(int seconds) {
    Time temp {*this};
    for (int i = 0; i < seconds; ++i) {
        --temp;
    }
    return temp;
}

Time& Time::operator+=(int seconds) {
    int total_seconds = get_total_seconds() + seconds;

    hour = (total_seconds / 3600) % 24;
    minute = (total_seconds / 60) % 60;
    second = total_seconds % 60;

    return *this;
}

Time Time::operator-=(int seconds) {
    *this = *this - seconds;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Time& time) {
    return os << time.to_string();
}

std::istream& operator>>(std::istream& is, Time& time) {
    std::string time_str {};
    is >> time_str;
    time = Time{time_str};
    return is;
}
