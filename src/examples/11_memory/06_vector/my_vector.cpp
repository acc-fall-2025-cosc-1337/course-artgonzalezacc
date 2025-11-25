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

MyVector::~MyVector()
{
    cout<<"Free memory at : "<<elements<<"\n";
    delete[] elements;
}