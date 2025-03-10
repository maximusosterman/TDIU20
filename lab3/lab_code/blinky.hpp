#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.hpp"

class Blinky : public Ghost
{

public:

    explicit Blinky(Pacman& pacman);
    ~Blinky() {};

    bool is_angry();
    void set_angry(bool bool_in);

    void set_chase_point() override;
    void set_scatter_point() override;

private:
    bool angry = false;


};

#endif // BLINKY_H
