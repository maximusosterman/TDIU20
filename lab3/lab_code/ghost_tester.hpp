#ifndef __GHOST_TESTER__
#define __GHOST_TESTER__

#include "ghost.hpp"
#include "given.hpp"

#include "blinky.hpp"
#include "clyde.hpp"
#include "pinky.hpp"

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

// Komplettering: Testprogrammet ska vara generellt och hantera ett
//    godtyckligt antal spöken. I och med att ni byggt ert program
//    med förutsättningen att alla spöken måste lagras som en variabel
//    funkar inte detta. Era spöken ska endast lagras i vektorn.

// Kommentar: Intressant att ni inkluderat kopieringskonstruktor
//    och kopieringsflyttoperator i test-klassen. Hur kommer det sig?

class Ghost_Tester
{

public:
    Ghost_Tester();
    ~Ghost_Tester();

    void run();

    Ghost_Tester(const Ghost_Tester&) = delete;
    Ghost_Tester& operator=(const Ghost_Tester&) = delete;

private:
    std::string to_draw(Point const& curr_pos);
    void draw_map();
    bool command_is_ghost_color(std::string const &command);


    bool scatter = false;

    Pacman pacman;
    Blinky* blinky;
    Clyde*  clyde;
    Pinky*  pinky;

    std::vector<Ghost*> ghosts;
};

#endif // __GHOST_TESTER__
