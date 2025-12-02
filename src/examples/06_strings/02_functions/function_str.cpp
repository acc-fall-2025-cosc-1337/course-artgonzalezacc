#include "function_str.h"

using std::cout;
using std::string;

void string_value_param(string lang) //will this be a copy parameter or direct access memory operator &
{
    for(auto ch: lang) //copy or direct access of a character in lang
    {
        ch = '.';
    }

    cout<<"output: "<<lang<<"\n";
}

void string_ref_param(std::string  &lang)
{
    for(auto ch: lang) //copy or direct access of a character in lang
    {
        ch = '.';
    }

    cout<<"output: "<<lang<<"\n";
}

void string_ref_param_ref_for(std::string  &lang)
{
    for(auto &ch: lang) //copy or direct access of a character in lang
    {
        ch = '.';
    }

    cout<<"output: "<<lang<<"\n";
}