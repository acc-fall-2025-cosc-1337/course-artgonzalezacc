#include<iostream>
#include<vector>

using std::cout;
using std::vector;

int main()
{
    auto num = 5;
    vector<int> nums{1, 5, 3};

    cout<<"Address of num: "<<&num<<"\n";
    cout<<"Address of nums: "<<&nums<<"\n";

    cout<<nums[0]<<"\n";
    cout<<"Address of number at index 0: "<<&nums[0]<<"\n";//gives us the address of value 1 in nums
    cout<<"Address of number at index 1: "<<&nums[1]<<"\n";//gives us the address of value 5 in nums
    cout<<"Address of number at index 0: "<<&nums[2]<<"\n";//gives us the address of value 3 in nums

    return 0;
}