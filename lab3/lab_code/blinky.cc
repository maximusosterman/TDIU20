#include "blinky.hpp"

Blinky::Blinky()
{
    color = "red";
    scatter_point = {0, 7};
    chase_point = {0, 0}; //TBD
}

bool Blinky::is_angry()
{
    return angry;
}

void Blinky::set_angry(bool bool_in)
{
    angry = bool_in;
}
