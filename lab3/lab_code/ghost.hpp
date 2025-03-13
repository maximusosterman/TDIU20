
#include "given.hpp"
#include <string>

#ifndef GHOST_H
#define GHOST_H


class Ghost
{

public:

    Ghost(Pacman& pacman) :
      color{},
      scatter_point{},
      chase_point{},
      position{},
      pacman{pacman} {};
    virtual ~Ghost() {};

    std::string get_color() const;
    Point get_scatter_point() const;
    Point get_chase_point() const;

    void set_position(Point const &position);
    Point get_position() const;

    virtual void set_chase_point(bool scatter) = 0;


protected:
   std::string color;
   Point scatter_point;
   Point chase_point;

   Point position;

   Pacman& pacman;
};

#endif //GHOST_H
