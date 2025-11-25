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

/*
1-Create temporary memory for v2
2-Copy values from v1 into v2 temporary memory
3-Delete v2 elements memory
4-Point v2 elements to temporary memory
5-Set v2.size to v1.size
6-Return a reference to itself
*/
MyVector& MyVector::operator=(const MyVector& v1)
{
    int* temp = new int[v1.size];

    for(auto i=0; i < v1.size; i++)
    {
        temp[i] = v1.elements[i];
    }

    cout<<"copy assignment delete memory at "<<elements<<"\n";
    delete[] elements;

    elements = temp;

    cout<<"copy assignment created memory at "<<elements<<"\n";
    
    size = v1.size;
    capacity = v1.capacity;

    return *this;
}

MyVector::~MyVector()
{
    cout<<"Free memory at : "<<elements<<"\n";
    delete[] elements;
}