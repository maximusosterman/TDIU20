#include "blinky.hpp"

Blinky::Blinky()
{
    color = "red";
    scatter_point = {0, 6};
    chase_point = Pacman::get_position();
}

bool Blinky::is_angry()
{
    return angry;
}

void Blinky::set_angry(bool bool_in)
{
    angry = bool_in;
}
