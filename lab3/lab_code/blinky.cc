#include "blinky.hpp"

Blinky::Blinky()
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

void Blinky::set_chase_point()
{

    std::cout << pacman.get_position().y;
    chase_point = pacman.get_position();
}

void Blinky::set_scatter_point() {
    if (is_angry()) {
        scatter_point = chase_point;
        return;
    }

    scatter_point = {18, 21};
}
