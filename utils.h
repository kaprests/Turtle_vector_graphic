#pragma once
#include "Turtle.h"
#include <math.h>


float randRange(float min, float max);

//Drawing functions:
void hexagon(Turtle *turtle);
void randomWalk(Turtle *turtle, int steps);

void koch(Turtle *turtle, float length, int level);
void snowFlake(Turtle* turtle, float length, int level);




