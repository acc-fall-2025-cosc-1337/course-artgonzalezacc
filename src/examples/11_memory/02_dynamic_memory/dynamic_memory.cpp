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

