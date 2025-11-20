#include "dynamic_memory.h"

using std::cout;

void use_dynamic_memory_array(const int SIZE)
{
    int* nums = new int[SIZE]{6, 1, 10};//create and initializes the dynamic array list on the heap

    for(auto i=0; i < SIZE; i++)
    {
        cout<<nums[i]<<"\n";
    }

    delete[] nums;

}

int* get_dynamic_memory(const int SIZE)
{
    int* nums = new int[SIZE];
    cout<<"Memory created at: "<<nums<<"\n";

    return nums;
}

void delete_dynamic_memory(int* array)
{
    cout<<"Deleting memory at: "<<array<<"\n";

    delete[] array;
}
