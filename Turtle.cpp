#include "Turtle.h"

Turtle::Turtle(Simple_window* win, Color c): 
    swin(win),
    x(win->x_max()/2), 
    y(win->y_max()/2),
    angle(0.0),
    lineWidth(1.0),
    color(c)
    {
    
}


void Turtle::drawLine(Point p1, Point p2){
    Line* line = new Line{p1, p2};
    line->set_color(this->color);
    line->set_style(Line_style(Line_style::solid, this->lineWidth));
    (this->swin)->attach(*line);
}


void Turtle::setPosition(float pos_x, float pos_y){
    this->x = pos_x;
    this->y = pos_y;
}


void Turtle::setAngle(float ang){
    this->angle = -ang;
}


void Turtle::forward(float distance){
    this->x = this->x + distance * cos(this->angle);
    this->y = this->y + distance * sin(this->angle);
}


void Turtle::backward(float distance){
    forward(-distance);
}


void Turtle::left(float ang){
    this->angle -= ang;
}


void Turtle::right(float ang){
    this->angle += ang;
}


