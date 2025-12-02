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

/*
1-Get v1.elements memory(switch/steal the data and make v1 empty)
2-Get size from v1
3-point v1.elements to nothing(nullptr)
4-set v1 size to 0
*/
MyVector::MyVector(MyVector&& v1)
: size{v1.size}, elements{v1.elements}
{
    cout<<"Move constructor - memory pointer switched from v1 to v1 "<<elements<<"\n";
    v1.elements = nullptr;
    v1.size = 0;
    v1.capacity = 0;
}

/*
1-Clear/delete original memory from v2
2-Point v1 elements to v2 elements
3-Get size from v1
4-Point v1.elements to nullptr
5-Set v1 size to 0
6-return a self reference(pointer to v2)
*/
MyVector& MyVector::operator=(MyVector&& v1)
{
    cout<<"Move assignment delete memory "<<elements<<"\n";
    delete[] elements;
    elements = v1.elements;
    size = v1.size;
    capacity = v1.capacity;
    cout<<"Move assignment switch pointer "<<elements<<"\n"; 

    v1.elements = nullptr;
    v1.size = 0;
    v1.capacity = 0;
    
    return *this;
}

/*
1-make sure that the new size is greater than capacity
2-Create temp memory of new_size allocation
3-copy values from old memory to new memory
4-delete the old memory
5-set elements to temp memory
6-set capacity to new_size
*/
void MyVector::Reserve(int new_size)
{
    if(new_size > capacity)
    {
        int* temp = new int[new_size];
        cout<<"Reserve temp memory created: "<<temp<<"\n";

        for(auto i=0; i < size; i++)
        {
            temp[i] = elements[i];
        }

        cout<<"Reserve delete old memory "<<elements<<"\n";
        delete[] elements;

        elements = temp;
        capacity = new_size;
    }
}

/*
PUSH BACK
1-if capacity is 0 call Reserve w RESERVE_DEFAULT_SIZE as function argument
2-else if size equal capacity call Reserve w capacity * RESERVE_DEFAULT_MULTIPLIER
3-add value to current elements[SIZE]
4-increment the size
*/
void MyVector::PushBack(int value)
{
    if(capacity == 0) //0 memory; grant 8 new slots of memory
    {
        Reserve(RESERVE_DEFAULT_SIZE);
    }
    else if(size == capacity)//have 3 slots; we use them; 3*2 to get 6 slots
    {
        Reserve(RESERVE_DEFAULT_MULTIPILER);
    }

    elements[size] = value;
    size++;
}

MyVector::~MyVector()
{
    cout<<"Free memory at : "<<elements<<"\n";
    delete[] elements;
}

//FREE FUNCTION - NOT PART OF MY VECTOR CLASS!!!!!!!!!!!!!!!!!!!
MyVector get_vector()  
{
    MyVector v1(3);
    return v1;
}
