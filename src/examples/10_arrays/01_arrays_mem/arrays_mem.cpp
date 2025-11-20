//write code for for stack_array and display each element to screen
#include "arrays_mem.h"

using std::cout;

//function prototype for stack_array
void create_stack_array()
{
    const int SIZE = 3;
    int nums[SIZE]{6, 1, 10};

    cout<<"Value: "<<nums[0]<<" Address: "<<&nums[0]<<"\n";
    cout<<"Value: "<<nums[1]<<" Address: "<<&nums[1]<<"\n";
    cout<<"Value: "<<nums[2]<<" Address: "<<&nums[2]<<"\n";

}

void arrays_and_pointers() //the name of a stack array is a pointer(behind scenes)
{
    const int SIZE = 3;
    int nums[SIZE]{6, 1, 10};
    cout<<nums<<"\n";
    
    int* num_ptr = nums;

    cout<<*num_ptr<<"\n";

    *num_ptr++; //jump 4 addresses (int is 4 bytes)

    cout<<*num_ptr<<"\n";

    *num_ptr++; //jump 4 addresses (int is 4 bytes)

    cout<<*num_ptr<<"\n";

    *num_ptr--; //jump 4 addresses (int is 4 bytes)

    cout<<*num_ptr<<"\n";

}

void display_array_via_pointer(int* array, const int SIZE)
{
    for(auto i=0; i < SIZE; i++)
    {
        cout<<array[i]<<"\n";
    }
}