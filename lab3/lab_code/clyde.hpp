#ifndef CLYDE_H
#define CLYDE_H

#include "ghost.hpp"
#include <string>
#include <cstdlib>
#include <cmath>

class Clyde : public Ghost
{

public:

    Clyde(Pacman& pacman);
    Point get_chase_point(bool scatter = false) override;

private:
    Point get_clyde_chase_point();
    int get_steps_from_pacman();

    int n {5};


};

#endif // CLYDE_H
