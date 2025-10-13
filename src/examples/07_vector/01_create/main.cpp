#include<iostream>
#include<vector>

using std::cout;
using std::vector;

int main()
{
    vector<int> nums;
    cout<<"size of vector: "<<nums.size()<<"\n";
    cout<<"capacity of vector: "<<nums.capacity()<<"\n";
    
    nums.push_back(1);
    cout<<"size of vector: "<<nums.size()<<"\n";
    cout<<"capacity of vector: "<<nums.capacity()<<"\n";

    nums.push_back(10);
    cout<<"size of vector: "<<nums.size()<<"\n";
    cout<<"capacity of vector: "<<nums.capacity()<<"\n";

    nums.push_back(5);
    cout<<"size of vector: "<<nums.size()<<"\n";
    cout<<"capacity of vector: "<<nums.capacity()<<"\n";

    nums.push_back(15);
    cout<<"size of vector: "<<nums.size()<<"\n";
    cout<<"capacity of vector: "<<nums.capacity()<<"\n";

    nums.push_back(20);
    cout<<"size of vector: "<<nums.size()<<"\n";
    cout<<"capacity of vector: "<<nums.capacity()<<"\n";

    return 0;
}