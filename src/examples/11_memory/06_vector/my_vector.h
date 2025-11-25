//
#include<iostream>

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

class MyVector
{

public:
    MyVector(); //blank/empty  list
    MyVector(int s); //a list of size s
    MyVector(const MyVector& v1);//copy constructor
    int& operator[](int index){return elements[index];}
    int& operator[](int index) const {return elements[index];}
    ~MyVector();//destructor
private:
    int size;
    int capacity;
    int* elements; //point to something eventually

};

#endif
