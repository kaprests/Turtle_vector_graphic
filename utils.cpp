#include "utils.h"

using namespace std;

double PI = acos(-1);


float randRange(float min, float max){
    return min + (max - min) * (static_cast<float>(rand())/RAND_MAX);
}


void hexagon(Turtle *turtle){
    Point a;
    Point b;
    float dist = (turtle->getWindow())->x_max()/4;

    turtle->setAngle(4*PI/3);
    turtle->forward(dist);
    turtle->setAngle(0);

    for (int i = 0; i < 6; i++){
        a = Point{static_cast<int>(turtle->getPositionX()), static_cast<int>(turtle->getPositionY())};
        turtle->forward(dist);
        b = Point{static_cast<int>(turtle->getPositionX()), static_cast<int>(turtle->getPositionY())};
        turtle->drawLine(a, b);
        turtle->left(PI/3);
    }
}


void randomWalk(Turtle *turtle, int steps) {
    Point a;
    Point b;
    
    for (int i = 0; i < steps; i++){
        float dist = randRange(0, 50);
        float angle = randRange(-PI, PI);

        a = Point{static_cast<int>(turtle->getPositionX()), static_cast<int>(turtle->getPositionY())};
        turtle->left(angle);
        turtle->forward(dist);
        b = Point{static_cast<int>(turtle->getPositionX()), static_cast<int>(turtle->getPositionY())};
        turtle->drawLine(a, b);
    }
}


void koch(Turtle *turtle, float length, int level){
        Point a;
        Point b;

    if (level == 0){
        a = Point{static_cast<int>(turtle->getPositionX()), static_cast<int>(turtle->getPositionY())};
        turtle->forward(length);
        b = Point{static_cast<int>(turtle->getPositionX()), static_cast<int>(turtle->getPositionY())};
        turtle->drawLine(a, b);
        
    }
    else{
        length = length/3;
        level -= 1;
        koch(turtle, length, level);
        turtle->right(PI/3);
        koch(turtle, length, level);
        turtle->left(2*PI/3);
        koch(turtle, length, level);
        turtle->right(PI/3);
        koch(turtle, length, level);
    }
}


void snowFlake(Turtle* turtle, float length, int level){
    turtle->setPosition((turtle->getWindow())->x_max()/4, 3*(turtle->getWindow())->y_max()/4);
    koch(turtle, length, level);
    turtle->setAngle(2*PI/3);
    koch(turtle, length, level);
    turtle->setAngle(4*PI/3);
    koch(turtle, length, level);
}







