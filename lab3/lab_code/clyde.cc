#include "clyde.hpp"

Clyde::Clyde()
{
    color = "orange";
    set_scatter_point();
    set_chase_point();

}

int Clyde::get_steps_from_pacman()
{

    // Number of steps is calculated by taking | pacman pos - clyde pos | (absoulute value)
    Point pacman_pos { pacman.get_position() };
    Point clyde_pos {get_position()};

    int delta_x { abs(pacman_pos.x - clyde_pos.x) };
    int delta_y { abs(pacman_pos.y - clyde_pos.y)  };

    return delta_x + delta_y;
}

void Clyde::set_chase_point()
{
    int steps_from_pacman { get_steps_from_pacman() };
    int n {5};
    if (steps_from_pacman > n)
    {
        chase_point = pacman.get_position();
        return;
    }

    chase_point = scatter_point;
}

void Clyde::set_scatter_point()
{
    scatter_point = {0, 0};

}
