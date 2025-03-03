
#include "given.hpp"
#include <string>

#ifndef GHOST_H
#define GHOST_H


class Ghost // base class
{

public:
    Ghost() {};
    virtual ~Ghost() {};

    std::string get_color() const;
    Point get_scatter_point() const;
    Point get_chase_point() const;

protected:
   std::string color;
   Point scatter_point;
   Point chase_point;

private:

   //Point get_chase_point();
   //Point get_scatter_point();
   //void set_position(Point);
   //void get_position();


   // virtual Point chase_point;
   // virtual Point scatter_point;
};

#endif //GHOST_H
