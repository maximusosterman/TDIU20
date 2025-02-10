#ifndef TIME_H
#define TIME_H

#include <string>

// Information om komplettering:
//   Siffrorna hänvisar till rättningsprotokollet som finns på
//   kurshemsidan -> läsning -> Literatur -> "Uppgruppens bedömningsprotokoll"
//   Kompletteringen kan gälla hela filen och alla filer i labben,
//   så får ni komplettering på en sak, kan samma sak förekomma på
//   fler ställen utan att jag skrivit det.
//
//   Komplettering lämnas in via sendlab efter senast en (1) vecka
//
//   Har ni frågor om kompletteringen kan ni maila mig.

// Komplettering: Kompilerar med varningar.

// Komplettering: Operatorer ska fungera enligt c++ standard.

// Komplettering (bonus): operator+= fungerar inte enligt C++-konvention. DONE

// Komplettering (bonus): Addition med ett heltal saknar hantering för det kommutativa fallet. DONE

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

Time operator+(Time& lhs, int seconds);
Time operator+(int seconds, Time& rhs);

std::ostream& operator<<(std::ostream& os, const Time& time);
std::istream& operator>>(std::istream& is, Time& time);


#endif