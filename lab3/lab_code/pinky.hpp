#ifndef PINKY_H
#define PINKY_H

#include "ghost.hpp"

class Pinky : public Ghost
{

public:
    Pinky(Pacman& pacman);

    Point get_chase_point(bool scatter = false) override;
};

#endif // PINKY_H
