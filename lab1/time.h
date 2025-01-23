#ifndef TIME_H
#define TIME_H

class Time {

public:
    Time();
    Time(int hour, int minute, int second);
    int get_hour() const;
    int get_minute() const;
    int get_second() const;

private:
    int hour;
    int minute;
    int second;
};

#endif