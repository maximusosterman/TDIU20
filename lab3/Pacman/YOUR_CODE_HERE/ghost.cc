std::string Ghost::get_color() const
{
    return color;
};

Point Ghost::get_scatter_point() const
{
    return scatter_point;
};

Point Ghost::get_chase_point() const
{
    return chase_point;
};

void Ghost::set_position(Point const &pos_in)
{
    position = pos_in;
};

Point Ghost::get_position() const
{
    return position;
}

Blinky::Blinky(Pacman& pacman)
      : Ghost(pacman)
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

void Blinky::set_chase_point(bool scatter)
{
    if (scatter)
    {
        chase_point = scatter_point;
        return;
    }

    chase_point = pacman.get_position();
}

void Blinky::set_scatter_point() {
    if (is_angry()) {
        scatter_point = chase_point;
        return;
    }

    scatter_point = {18, 21};
}


Clyde::Clyde(Pacman& pacman)
      : Ghost(pacman)
{
    color = "orange";
    scatter_point = {0, 0};
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

Pinky::Pinky(Pacman& pacman)
      : Ghost(pacman)
{
    color = "pink";
    scatter_point = {0, 21};
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
        chase_point =
        {
            .x = (pacman_pos.x + pacman_dir.x*2),
            .y = pacman_pos.y
        };
    } else // its y-axis
    {
        chase_point =
            {
                .x = pacman_pos.x,
                .y = (pacman_pos.y + pacman_dir.y*2)
            };

    }
}
