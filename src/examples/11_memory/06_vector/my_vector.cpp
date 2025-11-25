#include "my_vector.h"

using std::cout;

//
MyVector::MyVector() : size(0), capacity(0) //constructor
{

}

MyVector::MyVector(int s)
: size(s), capacity(s), elements{new int[size]}//create the dynamic memory of size s
{
    cout<<"Created elements memory at: "<<elements<<"\n";
}

MyVector::MyVector(const MyVector& v1)
: size(v1.size), capacity(v1.capacity), elements{new int[v1.size]} //deep copy
{
    cout<<"Constructor MyVector(const MyVector& v1) created memory at: "<<elements<<"\n";

    for(auto i=0; i < size; i++)
    {
        elements[i] = v1.elements[i];
    }
}

MyVector::~MyVector()
{
    cout<<"Free memory at : "<<elements<<"\n";
    delete[] elements;
}