#ifndef CLYDE_H
#define CLYDE_H

#include "ghost.hpp"
#include <string>
#include <cstdlib>
#include <cmath>

class Clyde : public Ghost
{

public:

    Clyde();
    ~Clyde() {};

    void update_chase_point(Point const& new_chase_point) override;

private:
    Point get_clyde_chase_point();
    int get_steps_from_pacman();



};

#endif // CLYDE_H
