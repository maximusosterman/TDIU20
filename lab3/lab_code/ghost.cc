#include "ghost.hpp"

// OBS: Jag lägger kompletteringskommentarerna för samtliga spökens
//    implementationsfiler i denna fil. Kommentarer här kan gälla för samtliga.

// Komplettering: Initiera era variabler med datamedlemsinitieringslistan,
//    se t.ex Blinky där färgen sätts i konstruktorns kropp, och hur
//    scatter_point även sätts i konstruktorns kropp.
// Komplettering: Ni hanterar chase- och scatter-points lite ineffektivt.
//    Tanken är inte att de värden som lagras i era spöken ska uppdateras
//    av ert testprogram eller körfilen. Hanteringen som ni gör i era
//    set_chase_point och set_scatter_point bör istället hanteras i
//    respektive get_chase_point / get_scatter_point.
//    Long story short, ni behöver ta bort set_chase/scatter_point
//    hantera detta i get_chase/scatter_point istället.
// Komplettering: set_position behöver kontrollera att den inskickade
//    positionen är inom spelplanen och informera anropande kod.
// Komplettering: Avståndet för Clyde ska beräknas som fågelvägen.
// Komplettering: Clydes n-värde ska inte vara hårdkodat i get_chase_point.

std::string Ghost::get_color() const
{
    return color;
};

Point Ghost::get_scatter_point() const
{
    return scatter_point;
};

Point Ghost::get_chase_point() const
{
    return chase_point;
};

void Ghost::set_position(Point const &pos_in)
{
    position = pos_in;
};

Point Ghost::get_position() const
{
    return position;
}
