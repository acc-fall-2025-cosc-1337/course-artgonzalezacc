#include "if.h"

bool is_vowel(char letter)
{
    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
}

bool is_consonant(char letter)
{
    return (letter >= 'a' && letter <= 'z') && !is_vowel(letter);
}