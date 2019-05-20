#include <iostream>
#include "Turtle.h"
#include "utils.h"

constexpr int xmax = 1000;
constexpr int ymax = 600;

using namespace std;


int main(){
    Graph_lib::Point tl{100, 100};
    Simple_window window{tl, xmax, ymax, "Turtle yo"};
    Turtle turtle{&window, Color::red};
    Turtle* turtle_pointer = &turtle;
    //hexagon(turtle_pointer);
    //randomWalk(turtle_pointer, 150);
    int levels{0};
    cout << "level: ";
    cin >> levels;
    cout << endl;
    snowFlake(turtle_pointer, 400.0, levels);
    window.wait_for_button();
}
