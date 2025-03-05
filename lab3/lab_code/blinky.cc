#include "blinky.hpp"

Blinky::Blinky()
{
    color = "red";
    scatter_point = {0, 6};
    update_chase_point({0, 0});
}



bool Blinky::is_angry()
{
    return angry;
}

void Blinky::set_angry(bool bool_in)
{
    angry = bool_in;
}

void Blinky::update_chase_point(Point const& new_chase_point)
{
    chase_point = new_chase_point;
}
