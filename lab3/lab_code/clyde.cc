#include "clyde.hpp"

int Clyde::get_steps_from_pacman()
{
    // Number of steps is calculated by | pacman pos - clyde pos | for both x znd y.
    Point pacman_pos { pacman.get_position() };
    Point clyde_pos {get_position()};

    int delta_x { abs(pacman_pos.x - clyde_pos.x) };
    int delta_y { abs(pacman_pos.y - clyde_pos.y)  };

    return sqrt((delta_x*delta_x) + (delta_y*delta_y));
}

Point Clyde::get_chase_point(bool scatter)
{
    int steps_from_pacman { get_steps_from_pacman() };
    if (steps_from_pacman > n && !scatter)
    {
        return pacman.get_position();
    }

    return scatter_point;
}
