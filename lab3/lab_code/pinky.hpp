#ifndef PINKY_H
#define PINKY_H

#include "ghost.hpp"

class Pinky : public Ghost
{

public:
    explicit Pinky(Pacman& pacman);
    ~Pinky() {};

    void set_chase_point(bool scatter = false) override;
};

#endif // PINKY_H
