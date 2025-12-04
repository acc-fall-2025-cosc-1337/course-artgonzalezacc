//
#include<iostream>

#ifndef MY_VECTOR_H
#define MY_VECTOR_H

template<typename T>
class MyVector
{

public:
    MyVector(); //blank/empty  list
    MyVector(int s); //a list of size s
    MyVector(const MyVector<T>& v1);//copy constructor Rule 1 of 3
    MyVector& operator=(const MyVector<T>& v1);//Rule 2 of 3 copy assignment
    MyVector(MyVector&& v); //rule 4 of 5 modern c++ MOVE constructor
    MyVector& operator=(MyVector<T>&& v1);//Rule 5 of 5 move assignment 
    T& operator[](int index){return elements[index];}
    T& operator[](int index) const {return elements[index];}
    void PushBack(T value);
    int Size() const {return size;}
    int Capacity()const {return capacity;}
    ~MyVector();//destructor Rule 3
private:
    int size;
    int capacity;
    T* elements{0}; //point to something eventually
    const int RESERVE_DEFAULT_SIZE{8};
    const int RESERVE_DEFAULT_MULTIPILER{2};
    void Reserve(int new_size);

};

MyVector<int> get_vector();

#endif
