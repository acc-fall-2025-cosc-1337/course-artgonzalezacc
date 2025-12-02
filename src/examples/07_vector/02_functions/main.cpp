#include<iostream>
#include<vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> nums0;
    nums0.push_back(5);
    nums0.push_back(10);
    nums0.push_back(3);

    nums0[0] = 15; //[] works like the memory operator -direct memory access

    for(auto &num: nums0)
    {   
        cout<<num<<"\n";
    }

    vector<int> nums1{1, 5, 3};
    for(auto &num: nums1)
    {
        cout<<num<<"\n";
    }

    vector<int> nums2(5, 10);

    for(auto &num: nums2)
    {
        cout<<num<<"\n";
    }
    
    cout<<"\n";

    vector<int> nums3 = nums2;

    for(auto &num: nums3)
    {
        cout<<num<<"\n";
    }

    return 0;
}