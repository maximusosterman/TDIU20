#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.hpp"
#include <string>

class Blinky : public Ghost
{

public:

    Blinky();
    ~Blinky() {};

private:
    // virtual Point chase_point = ;
    // virtual Point scatter_point;
};

#endif // BLINKY_H
