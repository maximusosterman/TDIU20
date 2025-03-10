#ifndef PINKY_H
#define PINKY_H

#include "ghost.hpp"

class Pinky : public Ghost
{

public:
    explicit Pinky(Pacman& pacman);
    ~Pinky() {};

    void set_chase_point() override;
    void set_scatter_point() override;
};

#endif // PINKY_H
