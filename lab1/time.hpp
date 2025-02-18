#ifndef TIME_H
#define TIME_H

#include <string>

// Komplettering: Kompilerar med varningar.

class Time {

public:
    Time(int hour, int minute, int second);
    Time(std::string const& time_string = "00:00:00");

    int get_hour() const;
    int get_minute() const;
    int get_second() const;

    void set_hour(int hour_in);
    void set_minute(int minute_in);
    void set_second(int second_in);

    bool is_am() const;
    std::string to_string(bool twentyfour_hour_format = true) const&;

    bool operator==(const Time& rhs) const;
    bool operator!=(const Time& rhs) const;

    bool operator<(const Time& rhs) const;
    bool operator<=(const Time& rhs) const;

    bool operator>(const Time& rhs) const;
    bool operator>=(const Time& rhs) const;

    Time& operator++();
    Time operator++(int);

    Time& operator--();
    Time operator--(int);

    Time& operator+=(int seconds);

    Time operator-(int seconds);
    Time operator-=(int seconds);

private:
    int hour;
    int minute;
    int second;

    //helpers
    void check_valid_clock_range(int hour, int minute, int second) const;
    void format_12h(std::string& hour_str, std::string& am_pm) const;
    int get_total_seconds() const;

};

Time operator+(const Time& lhs, int seconds);
Time operator+(int seconds, const Time& rhs);

std::ostream& operator<<(std::ostream& os, const Time& time);
std::istream& operator>>(std::istream& is, Time& time);


#endif // TIME_H
