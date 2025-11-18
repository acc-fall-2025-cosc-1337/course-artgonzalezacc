//circle.h
#include "shape.h"
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle: public Shape //if w inherit from an abstract and don't overwrite draw; Circle is an abstract class!!!!
{
public:
    void draw(){std::cout<<"Draw circle\n";}
};

#endif