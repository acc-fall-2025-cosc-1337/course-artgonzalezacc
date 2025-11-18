//shape.h
#include<iostream>

#ifndef SHAPE_H
#define SHAPE_H

class Shape//abstract class-a class with at least one pure virtual function
{
public:
    virtual void draw() = 0;//make this function a pure virtual function    
};

#endif