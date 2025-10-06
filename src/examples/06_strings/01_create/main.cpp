#include<iostream>
#include<string>

using std::cout;
using std::string;

int main()
{
    string name = "C++";
    cout<<name<<"\n";

    cout<<"size of string: "<<name.size()<<"\n";
    cout<<"capacity of string: "<<name.capacity()<<"\n";

    name.append("i");

    cout<<"size of string: "<<name.size()<<"\n";
    cout<<"capacity of string: "<<name.capacity()<<"\n";

    name.append("s");
    name.append(" ");
    name.append("c");
    name.append("o");
    name.append("o");
    name.append("l");

    cout<<"size of string: "<<name.size()<<"\n";
    cout<<"capacity of string: "<<name.capacity()<<"\n";

    name.append(" ");
    name.append("c");
    name.append("o");
    name.append("o");
    name.append("l");

    cout<<name<<"\n";
    cout<<"size of string: "<<name.size()<<"\n";
    cout<<"capacity of string: "<<name.capacity()<<"\n";

    name.append("!");

    cout<<name<<"\n";
    cout<<"size of string: "<<name.size()<<"\n";
    cout<<"capacity of string: "<<name.capacity()<<"\n";

    name.append(" ");
    name.append("c");
    name.append("o");
    name.append("o");
    name.append("l");
    name.append(" ");
    name.append("c");
    name.append("o");
    name.append("o");
    name.append("l");
    name.append(" ");
    name.append("c");
    name.append("o");
    name.append("o");
    name.append("l");

    cout<<name<<"\n";
    cout<<"size of string: "<<name.size()<<"\n";
    cout<<"capacity of string: "<<name.capacity()<<"\n";
    return 0;
}