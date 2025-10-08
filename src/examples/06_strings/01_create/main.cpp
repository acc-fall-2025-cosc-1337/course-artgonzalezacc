#include<iostream>
#include<string>

using std::cout;
using std::string;

int main()
{
    string s1; //empty string
    s1.append("abc");
    cout<<s1<<"\n\n";

    string s2("C++");
    cout<<s2<<"\n\n";

    string s3(9, 'a');
    cout<<s3<<"\n\n";

    string s4("abcdefg", 3);
    cout<<s4<<"\n\n";

    return 0;
}