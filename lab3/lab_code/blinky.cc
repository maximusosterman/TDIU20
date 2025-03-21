#include "blinky.hpp"

bool Blinky::is_angry()
{
    return angry;
}

void Blinky::set_angry(bool bool_in)
{
    angry = bool_in;
}

Point Blinky::get_chase_point(bool scatter)
{
    if (is_angry() or !scatter)
    {
        return pacman.get_position();
    }

    return scatter_point;
}
