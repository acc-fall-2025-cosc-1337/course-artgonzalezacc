#include "char.h"
#include <iostream>

int main()
{
    char input_char;
    std::cout << "Enter a character: ";
    std::cin >> input_char;

    int ascii_value = get_char_ascii_value(input_char);
    std::cout << "The ASCII value of '" << input_char << "' is " << ascii_value << std::endl;

    return 0;
}