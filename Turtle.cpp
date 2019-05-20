#include "Turtle.h"

Turtle::Turtle(Simple_window* win, Color c): 
    swin(win),
    pos(Point{win->x_max()/2, win->y_max()/2 }),
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


void Turtle::setPosition(Point point){
    this->pos = point;
}


void Turtle::setAngle(float ang){
    this->angle = -ang;
}


void Turtle::forward(float distance){
    float x = (this->pos).x + distance * cos(this->angle);
    float y = (this->pos).y + distance * sin(this->angle);
    this->pos = Point{static_cast<int>(x), static_cast<int>(y)};
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


