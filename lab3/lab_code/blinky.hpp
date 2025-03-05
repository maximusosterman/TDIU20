#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.hpp"
#include <string>

class Blinky : public Ghost
{

public:

    Blinky();
    ~Blinky() {};

    bool is_angry();
    void set_angry(bool bool_in);

    void update_chase_point(Point const& new_chase_point) override;

private:
    bool angry = false;
};

#endif // BLINKY_H
