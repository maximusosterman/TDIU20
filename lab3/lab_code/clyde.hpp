#ifndef CLYDE_H
#define CLYDE_H

#include "ghost.hpp"
#include <string>
#include <cstdlib>
#include <cmath>

class Clyde : public Ghost
{

public:

    explicit Clyde(Pacman& pacman) : Ghost(pacman) {};

    Clyde();
    ~Clyde() {};

    void set_chase_point() override;
    void set_scatter_point() override;

private:
    Point get_clyde_chase_point();
    int get_steps_from_pacman();



};

#endif // CLYDE_H
