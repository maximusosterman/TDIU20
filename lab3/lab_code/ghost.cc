#include "ghost.hpp"

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
