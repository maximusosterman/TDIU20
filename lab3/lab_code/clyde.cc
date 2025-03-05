#include "clyde.hpp"

Clyde::Clyde()
{
    color = "orange";
    scatter_point = {0, 0};
    chase_point = get_clyde_chase_point();

}

int Clyde::get_steps_from_pacman()
{

    // Number of steps is calculated by taking | pacman pos - clyde pos | (absoulute value)
    Point pacman_pos {Pacman::get_position()};
    Point clyde_pos {get_position()};

    int delta_x { abs(pacman_pos.x - clyde_pos.x) };
    int delta_y { abs(pacman_pos.y - clyde_pos.y)  };

    return delta_x + delta_y;
}

Point Clyde::get_clyde_chase_point()
{

    int steps_from_pacman {get_steps_from_pacman()};
    int n {3};

    if (steps_from_pacman > n)
    {
        return Pacman::get_position();
    }

    return scatter_point;

}
