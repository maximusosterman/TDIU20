#include "blinky.hpp"

Blinky::Blinky(Pacman& pacman)
      : Ghost(pacman)
{
    color = "red";
    set_scatter_point();
    set_chase_point();

}

bool Blinky::is_angry()
{
    return angry;
}

void Blinky::set_angry(bool bool_in)
{
    angry = bool_in;
}

void Blinky::set_chase_point(bool scatter)
{
    if (scatter)
    {
        chase_point = scatter_point;
        return;
    }

    chase_point = pacman.get_position();
}

void Blinky::set_scatter_point() {
    if (is_angry()) {
        scatter_point = chase_point;
        return;
    }

    scatter_point = {18, 21};
}
