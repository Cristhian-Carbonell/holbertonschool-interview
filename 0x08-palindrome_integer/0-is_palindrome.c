#include "palindrome.h"

/**
 *
 */
int is_palindrome(unsigned long n)
{
    int reversed = 0;
    int remainder, original;

    original = n;
    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    if (original == reversed)
        return (1);
    else
        return (0);

    return (0);
}