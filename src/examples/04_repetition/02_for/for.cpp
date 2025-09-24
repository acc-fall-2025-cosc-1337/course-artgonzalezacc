#include "for.h"
#include<iostream>

void display_even_numbers(int n) 
{
    // Use a for loop to iterate from 0 to n
    for (int i = 0; i <= n; i += 2) 
    { // Increment by 2 to get even numbers
        std::cout << i << " "; // Print the even number followed by a space
    }
    std::cout << std::endl; // Print a newline at the end
}   // End of display_even_numbers

void user_controlled_for_loop()
{
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    for(int i = 0; i < n; ++i) 
    {
        std::cout << i+1 << " ";
    }
    std::cout << std::endl;
}

 

