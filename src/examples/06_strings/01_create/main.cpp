#include<iostream>
#include<string>

using std::cout;
using std::string;

int main()
{
    string lang = "C++";
    cout<<lang[1]<<"\n\n";
    lang[1] = '.';
    cout<<lang[1]<<"\n";

    return 0;
}