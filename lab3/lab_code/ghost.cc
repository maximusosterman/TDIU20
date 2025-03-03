#include "ghost.hpp"

std::string Ghost::get_color() const {
    return color;
};

Point Ghost::get_scatter_point() const {
    return scatter_point;
};

Point Ghost::get_chase_point() const {
    return chase_point;
};
