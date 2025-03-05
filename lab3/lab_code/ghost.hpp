
#include "given.hpp"
#include <string>

#ifndef GHOST_H
#define GHOST_H


class Ghost : public Pacman
{

public:
    Ghost() {};
    virtual ~Ghost() {};

    std::string get_color() const;
    Point get_scatter_point() const;
    Point get_chase_point() const;

    void set_position(Point const &position);
    Point get_position() const;

    virtual void update_chase_point(Point const& new_chase_point) = 0;

    using Pacman::get_position;

protected:
   std::string color;
   Point scatter_point;
   Point chase_point;

   Point position;

private:

   //Point get_chase_point();
   //Point get_scatter_point();
   //void set_position(Point);
   //void get_position();


   // virtual Point chase_point;
   // virtual Point scatter_point;
};

#endif //GHOST_H
