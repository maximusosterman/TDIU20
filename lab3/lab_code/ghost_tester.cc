#include "ghost_tester.hpp"

using namespace std;

Ghost_Tester::Ghost_Tester()
     :  pacman {},
        blinky {},
        clyde {}
{
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

        if (command == "pos")
        {
            Point new_pos {};
            iss >> new_pos.x >> new_pos.y;
            pacman.set_position(new_pos);
            blinky.update_chase_point(pacman.get_position());
            //pinky.update_chase_point(pacman.get_position())
            clyde.update_chase_point(pacman.get_position());

        }

        else if (command == "scatter")
        {
            scatter = !scatter;
        }

        else if (command == "red")
        {
            Point new_pos {};
            iss >> new_pos.x >> new_pos.y;
            blinky.set_position(new_pos);
        }

        else if (command == "orange")
        {
            Point new_pos {};
            iss >> new_pos.x >> new_pos.y;
            clyde.set_position(new_pos);
        }
        else if (command == "dir")
        {
        }
        else if (command == "quit")
        {
            break;
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

        if (blinky.get_chase_point() == curr_pos)
        {
            to_draw[0] = 'r';
        };

        to_draw[1] = '@';
    }

    else if (blinky.get_position() == curr_pos)
    {
        to_draw[1] = 'R';
    }

    // if red

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
