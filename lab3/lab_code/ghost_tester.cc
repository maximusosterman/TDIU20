#include "ghost_tester.hpp"

using namespace std;

Ghost_Tester::Ghost_Tester()
     :  pacman {},
        blinky {pacman},
        clyde {pacman},
        pinky {pacman}
        {}

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

        if (command == "scatter")
        {
            scatter = !scatter;
        }

        else if (command == "anger")
        {
            blinky.set_angry(!blinky.is_angry());
        }

        if (
                command == pinky.get_color()
                or command == clyde.get_color()
                or command == blinky.get_color()
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

            else if (command == pinky.get_color()) {
                pinky.set_position(new_pos);
            }

            else if (command == blinky.get_color()) {
                blinky.set_position(new_pos);
            }

            else if (command == clyde.get_color()) {
                clyde.set_position(new_pos);
            }
        }

        else if (command == "quit")
        {
            break;
        }

        blinky.set_chase_point(scatter);
        pinky.set_chase_point(scatter);
        clyde.set_chase_point(scatter);

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

        if (clyde.get_chase_point() == curr_pos)
        {
            to_draw[0] = std::tolower(clyde.get_color().at(0));
        }

        else if (blinky.get_chase_point() == curr_pos)
        {
            to_draw[0] = std::tolower(blinky.get_color().at(0));

        }

        to_draw[1] = '@';
    }

    else if (blinky.get_position() == curr_pos)
    {
        to_draw[0] = std::toupper(blinky.get_color().at(0));

    }

    else if (clyde.get_position() == curr_pos)
    {
        to_draw[0] = std::toupper(clyde.get_color().at(0));

    }

    else if (clyde.get_chase_point() == curr_pos)
    {
        to_draw[0] = std::tolower(clyde.get_color().at(0));

    }

    else if (pinky.get_position() == curr_pos)
    {
        to_draw[0] = std::toupper(pinky.get_color().at(0));

    }

    else if (pinky.get_chase_point() == curr_pos)
    {
        to_draw[0] = std::tolower(pinky.get_color().at(0));
    }

    else if (blinky.get_chase_point() == curr_pos)
    {
        to_draw[0] = std::tolower(blinky.get_color().at(0));
    }


    return to_draw;
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
