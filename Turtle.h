#pragma once
#include <iostream>
#include <math.h>
#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

class Turtle {
protected:
    Point pos; // current position
    //float x, y; should implement with int x, y instead, but too much work rn.
    float angle;
    float lineWidth;
    Color color;
    Simple_window* swin;
public:
    void drawLine(Point p1, Point p2);

    //constructor:
    Turtle(Simple_window* win, Color c);

    void clear(); //maybe not needed
    // geters:
    Point getPosition() { return this->pos; };
    float getAngle() { return this->angle; };
    //int getWidth() { return this->width; };
    //int getHeight(){ return this->height; };
    Color getColor() { return this->color; };
    Simple_window* getWindow() { return swin; };

    //seters:
    void setPosition(Point point);
    void setAngle(float ang);
    void setColor(Color c) { this->color = c; };
    void setLineWidth(float lw);
    
    //Virtual shit:
    virtual void forward(float distance);
    virtual void backward(float distance);
    virtual void left(float ang);
    virtual void right(float ang);
};
