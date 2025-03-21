
#include "given.hpp"
#include <string>

#ifndef GHOST_H
#define GHOST_H

// OBS: Jag lägger kompletteringskommentarerna för samtliga spökens
//    header-filer i denna fil. Kommentarer här kan gälla för samtliga.

// Kommentar: Varför har ni satt konstruktorer till explicit? Motivera
//    gärna detta och vad det gör.

// Komplettering: Era ärvda spöken ska inte ha destrukturer.
// Komplettering: Ni har inte skickat in alla filer. Då ni döpt om
//    given.h till given.hpp så utgår jag ifrån att ni har gjort
//    andra ändringar i filen, och bör därför skicka in den med.
//

class Ghost
{

public:

    Ghost(Pacman& pacman, std::string const& color, Point const& scatter_point, Point const& position) :
      color{color},
      scatter_point{scatter_point},
      chase_point{},
      position{position},
      pacman{pacman} {};
    virtual ~Ghost() {};

    std::string get_color() const;
    Point get_scatter_point() const;
    virtual Point get_chase_point(bool scatter = false) = 0;

    void set_position(Point const &position);
    Point get_position() const;


protected:
   std::string color;
   Point scatter_point;
   Point chase_point;

   Point position;

   Pacman& pacman;
};

#endif //GHOST_H
