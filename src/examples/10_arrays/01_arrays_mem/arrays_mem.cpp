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