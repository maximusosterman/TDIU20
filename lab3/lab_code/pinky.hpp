#ifndef PINKY_H
#define PINKY_H

#include "ghost.hpp"

class Pinky : public Ghost
{

public:
    using Ghost::Ghost;

    Point get_chase_point(bool scatter = false) override;
};

#endif // PINKY_H
