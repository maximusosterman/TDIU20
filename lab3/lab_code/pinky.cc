#include "pinky.hpp"

Point Pinky::get_chase_point(bool scatter)
{
    if (scatter)
    {
        return scatter_point;
    }

    Point pacman_dir { pacman.get_direction() };
    Point pacman_pos { pacman.get_position() };

    if (pacman_dir.x != 0) // Pacman goes in x-axis
    {
        return {pacman_pos.x + pacman_dir.x*2, pacman_pos.y};
    } else // its y-axis
    {
        return {pacman_pos.x, pacman_pos.y + pacman_dir.y*2};
    }
}
