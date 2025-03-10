#ifndef BLINKY_H
#define BLINKY_H

#include "ghost.hpp"
#include <string>

class Blinky : public Ghost
{

public:

    Blinky();
    ~Blinky() {};

    bool is_angry();
    void set_angry(bool bool_in);

    void set_chase_point(Point const& new_chase_point) override;

    void update_scatter_point();

private:
    bool angry = false;


};

#endif // BLINKY_H
