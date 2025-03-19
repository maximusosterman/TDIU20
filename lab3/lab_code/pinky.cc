#include "pinky.hpp"

Pinky::Pinky(Pacman& pacman)
      : Ghost(pacman)
{
    color = "pink";
    scatter_point = {0, HEIGHT-1};
    set_chase_point();
}

void Pinky::set_chase_point(bool scatter)
{
    if (scatter)
    {
        chase_point = scatter_point;
        return;
    }

    Point pacman_dir { pacman.get_direction() };
    Point pacman_pos { pacman.get_position() };

    if (pacman_dir.x != 0) // Pacman goes in x-axis
    {
        chase_point = {pacman_pos.x + pacman_dir.x*2, pacman_pos.y};
    } else // its y-axis
    {
        chase_point = {pacman_pos.x, pacman_pos.y + pacman_dir.y*2};
    }
}
