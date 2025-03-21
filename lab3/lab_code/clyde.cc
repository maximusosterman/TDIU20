#include "clyde.hpp"

Clyde::Clyde(Pacman& pacman)
      : Ghost(pacman)
{
    color = "orange";
    scatter_point = {0, 0};
    set_chase_point();

}

int Clyde::get_steps_from_pacman()
{

    // Number of steps is calculated by | pacman pos - clyde pos | for both x znd y.
    Point pacman_pos { pacman.get_position() };
    Point clyde_pos {get_position()};

    int delta_x { abs(pacman_pos.x - clyde_pos.x) };
    int delta_y { abs(pacman_pos.y - clyde_pos.y)  };

    return sqrt((delta_x*delta_x) + (delta_y*delta_y));
}

void Clyde::set_chase_point(bool scatter)
{

    int steps_from_pacman { get_steps_from_pacman() };
    int n {5};
    if (steps_from_pacman > n && !scatter)
    {
        chase_point = pacman.get_position();
        return;
    }

    chase_point = scatter_point;
}
