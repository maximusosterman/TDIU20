#include "pinky.hpp"

Pinky::Pinky(Pacman& pacman)
      : Ghost(pacman)
{
    color = "pink";
    set_scatter_point();
    set_chase_point();
}

void Pinky::set_chase_point()
{

}

void Pinky::set_scatter_point()
{
    scatter_point = {0, 21};
}
