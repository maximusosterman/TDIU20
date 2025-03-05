#ifndef __GHOST_TESTER__
#define __GHOST_TESTER__

#include "ghost.hpp"
#include "blinky.hpp"

#include "given.hpp"

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Ghost_Tester
{

public:
    Ghost_Tester();
    void run();

private:

    std::string to_draw(Point const& curr_pos);
    void draw_map();

    bool scatter = false;

    Pacman pacman;
    Blinky blinky;
};

#endif // __GHOST_TESTER__
