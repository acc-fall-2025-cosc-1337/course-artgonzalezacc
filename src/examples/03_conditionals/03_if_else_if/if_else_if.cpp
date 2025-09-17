//write include statement for if_else header file
#include "if_else_if.h"

using std::string;

string get_generation(int year)
{
    string generation = "";

    if(year >= 1996 && year <= 2014) 
    {
        generation = "Centenial";
    }
    else if(year >= 1977 && year <=1995)
    {
        generation = "Millenial";
    }
    else if(year >= 1965 && year <=1976)
    {
        generation = "Generation X";
    }
    else if(year >= 1946 && year <=1964)
    {
        generation = "Baby boomer";
    }
    else if(year >= 1925 && year <=1945)
    {
        generation = "Silent Generation";
    }
    else
    {
        generation = "Invalid Year";
    }
    

    return generation;
}


