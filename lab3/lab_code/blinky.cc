#include "blinky.hpp"

Blinky::Blinky(Pacman& pacman)
      : Ghost(pacman)
{
    color = "red";
    scatter_point = {WIDTH-1, HEIGHT-1};
    get_chase_point();

}

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
