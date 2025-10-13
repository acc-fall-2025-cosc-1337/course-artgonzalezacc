#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<double> doubles;
    doubles.push_back(10.59);
    doubles.push_back(21.99);
    doubles.push_back(9.79);

    cout<<doubles[0]<<"\n";
    cout<<doubles[1]<<"\n";
    cout<<doubles[2]<<"\n";

    vector<string> strings;
    string str = "C++";
    strings.push_back(str);
    str = "Python";
    strings.push_back(str);
    str = "Java";
    strings.push_back(str);
    str = "C#";
    strings.push_back(str);

    for(long unsigned int i=0; i < strings.size(); i++) {
        cout<<strings[i]<<"\n";
    }

    return 0;
}