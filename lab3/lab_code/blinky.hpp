#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.hpp"

class Blinky : public Ghost
{

public:

    Blinky(Pacman& pacman);

    bool is_angry();
    void set_angry(bool bool_in);

    Point get_chase_point(bool scatter = false) override;

private:
    bool angry = false;
};

#endif // BLINKY_H
