#include "blinky.hpp"

Blinky::Blinky()
{
    color = "red";
    update_scatter_point();
    set_chase_point({0, 0});

}



bool Blinky::is_angry()
{
    return angry;
}

void Blinky::set_angry(bool bool_in)
{
    angry = bool_in;
}

void Blinky::set_chase_point(Point const& new_chase_point)
{
    chase_point = new_chase_point;
}

void Blinky::update_scatter_point() {
    if (is_angry()) {
        scatter_point = chase_point;
        return;
    }

    scatter_point = {18, 21};
}
