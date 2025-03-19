#include "ghost_tester.hpp"

using namespace std;

// Komplettering: För att hitta Blinky i listan av spöken ska dynamic_cast användas.
// Komplettering: I testprogrammet verkar Blinky fortfarande springa till sin scatter
//    point även när angry är true.
// Komplettering: Koden kör med minnesläckor.

// Kommentar: Sätt gärna olika startpositioner på alla spöken så att de inte börjar
//    på samma punkt allihopa.

Ghost_Tester::Ghost_Tester()
     :  pacman {},
        blinky{new Blinky{pacman}},
        clyde{new Clyde{pacman}},
        pinky{new Pinky{pacman}},
        ghosts {blinky, clyde, pinky} 

        {
            blinky->set_position({0, HEIGHT - 1});  // Överst till vänster
            clyde->set_position({WIDTH - 1, HEIGHT - 1});  // Överst till höger
            pinky->set_position({WIDTH  -1, 0});  // Högra bottenhörnet
        }

Ghost_Tester::~Ghost_Tester(){
    for (Ghost* ghost : ghosts) 
    {
        delete ghost;
    }
    
    ghosts.clear();
}
        


void Ghost_Tester::run()
{
    while(true)
    {
        draw_map();
        cout << "> ";

        string line {};
        getline(cin, line);
        istringstream iss {line}; 

        string command {};
        iss >> command;

        if (command == "quit")
        {
            break;
        }

        else if (command == "scatter")
        {
            if (!scatter)
            {
                scatter = true;
            }
        }

        else if (command == "chase")
        {
            if (scatter) {
                scatter = false;
            }
        }

        else if (command == "anger")
        {
            for (Ghost* ghost : ghosts)
            {
                Blinky* blinky = dynamic_cast<Blinky*>(ghost);
                if (blinky) {
                    blinky->set_angry(!blinky->is_angry());
                    break;
                }
            }
        }

        if (
                command_is_ghost_color(command)
                or command == "pos"
                or command == "dir"
                )
        {
            Point new_pos {};
            iss >> new_pos.x >> new_pos.y;

            if (command == "dir") {
                //pos acts as dir here, same data type
                pacman.set_direction(new_pos);
            }

            else if (command == "pos") {
                pacman.set_position(new_pos);
            }

            for (Ghost* ghost : ghosts)
            {
                if (command == ghost->get_color())
                {
                    ghost->set_position(new_pos);
                    break;
                }
            }
        }

        for (Ghost* ghost: ghosts)
        {
            ghost->set_chase_point(scatter);
        }

    }
}

/*
  En hjälpfunktion som avgör vilka två tecken som ska ritas ut för en given position på
  spelplanen.
 */
string Ghost_Tester::to_draw(Point const& curr_pos)
{
    string to_draw{"  "};

    if (pacman.get_position() == curr_pos)
    {

        if (clyde->get_chase_point() == curr_pos)
        {
            to_draw[0] = std::tolower(clyde->get_color().at(0));
        }

        else if (blinky->get_chase_point() == curr_pos)
        {
            to_draw[0] = std::tolower(blinky->get_color().at(0));

        }

        to_draw[1] = '@';
    }

    for (Ghost* ghost : ghosts)
    {
        if (ghost->get_position() == curr_pos)
        {
            to_draw[0] = std::toupper(ghost->get_color().at(0));
        }

        else if (ghost->get_chase_point() == curr_pos)
        {
            to_draw[0] = std::tolower(ghost->get_color().at(0));

        }
    }

    return to_draw;
}

bool Ghost_Tester::command_is_ghost_color(std::string const &command)
{
    for (Ghost* ghost : ghosts)
    {
        if (command == ghost->get_color())
        {
            return true;
        }
    }

    return false;
}

/*
  En hjälpfunktion för att rita ut spelplanen för testprogrammet.

  Itererar över varje rad och column i kartan. Index för raderna är flippade för att placera
  y = 0 längst ned.

  Varje punkt i kartan ritas som två tecken eftersom ett tecken i terminalen är ca dubbelt så
  högt som det är brett.
*/
void Ghost_Tester::draw_map()
{
    cout << "+" << setfill('-') << setw(WIDTH * 2) << "-" << "+\n";

    for (int y {HEIGHT - 1}; y >= 0; --y)
    {
        cout << "|";
        for (int x {}; x < WIDTH; ++x)
        {
            cout << to_draw( Point{x,y} );
        }
        cout << "|\n";
    }

    cout << "+" << setfill('-') << setw(WIDTH * 2) << "-" << "+" << endl;
}
