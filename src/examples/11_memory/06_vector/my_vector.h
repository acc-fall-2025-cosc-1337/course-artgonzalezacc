//
#include<iostream>

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

class MyVector
{

public:
    MyVector(); //blank/empty  list
    MyVector(int s); //a list of size s
    ~MyVector();//destructor
private:
    int size;
    int capacity;
    int* elements; //point to something eventually

};

#endif
