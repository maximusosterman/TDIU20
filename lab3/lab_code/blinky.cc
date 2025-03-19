w#include "blinky.hpp"

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

    if (is_angry()) {
        chase_point = pacman.get_position();
        return;
    }

    if (scatter)
    {
        chase_point = scatter_point;
        return;
    }

    chase_point = pacman.get_position();
}

void Blinky::set_scatter_point() {
    scatter_point = {WIDTH-1, HEIGHT-1};
}
