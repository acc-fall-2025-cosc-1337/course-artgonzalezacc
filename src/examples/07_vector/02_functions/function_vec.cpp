#include "function_vec.h"

using std::cout;
using std::vector;

void use_vector_val_param(std::vector<int> nums)
{
    nums[0]  = -1;
}

void loop_vector_w_while()
{
    vector<double> nums{8.5, 6.1, 10.2};
    long unsigned int index = 0;

    while(index < nums.size())
    {
        cout<<nums[index]<<"\n";
        index++;
    }

}

void loop_vector_w_for()
{
    vector<int> nums{10, 5, 7};

    for(long unsigned int i=0; i < nums.size(); i++)
    {
        cout<<nums[i]<<"\n";
    }
}

void loop_vector_w_for_range()
{
    vector<int> nums{10, 5, 8};

    for(auto &num:nums) 
    {
        cout<<num<<"\n";
    }
}