#include "clyde.hpp"
#include "ghost.hpp"

Clyde::Clyde()
{
    color = "orange";
    scatter_point = {0, 0};
    update_chase_point(get_clyde_chase_point());

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

void Clyde::update_chase_point(Point const& new_chase_point)
{
    chase_point = new_chase_point;
}


Point Clyde::get_clyde_chase_point()
{

    int steps_from_pacman { get_steps_from_pacman() };
    int n {3};

    if (steps_from_pacman > n)
    {
        return pacman.get_position();
    }

    return scatter_point;

}
