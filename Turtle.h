#pragma once
#include <iostream>
#include <math.h>
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

class Turtle {
protected:
    float x, y; //positon
    float angle;
    float lineWidth;
    Color color;
    Simple_window* swin;
public:
    void drawLine(Point p1, Point p2);

    //constructor:
    Turtle(Simple_window* win, Color c);

    // geters:
    float getPositionX() { return this->x; };
    float getPositionY() { return this->y; };
    float getAngle() { return this->angle; };
    Color getColor() { return this->color; };
    Simple_window* getWindow() { return swin; };

    //seters:
    void setPosition(float pos_x, float pos_y);
    void setAngle(float ang);
    void setColor(Color c) { this->color = c; };
    void setLineWidth(float lw);
    
    //Virtual shit:
    virtual void forward(float distance);
    virtual void backward(float distance);
    virtual void left(float ang);
    virtual void right(float ang);
};
