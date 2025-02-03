/*o
--------------------------------------------------
Project: a1q1
File:    mychar.c
Author:  Jessica Desmond
Version: 2025-01-14
--------------------------------------------------
*/

#include "mychar.h"

/**
 * Determine the type of a char character.
 *
 * @param c - char type
 * @return - 0 if c is a digit
             1 if c is an arithmetic operator
             2 if c is the left parenthesis (
             3 if c is the right parenthesis )
             4 if c is an English letter;
             otherwise -1.
 */

// For my type search up ascii chart and get range for the types

/**
 * COMPARING ASCII CHAR TO ITS NUMBER VAL
 *  mix and match char r;
r = 82;
if (r == 'R') { // will be true
*/

int mytype(char c)
{
    // your code
    if (c >= '0' && c <= '9')
    {
        return 0;
    }
    if (c == '+' || c == '*' || c == '-' || c == '%')
    {
        return 1;
    }
    else if (c == '(')
    {
        return 2;
    }
    else if (c == ')')
    {
        return 3;
    }
    else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    {
        return 4;
    }
    // Else here is redundant because if the program has reached this point,
    // everything else obviously doesn't apply
    return -1; // not a digit, operator, parenthesis, or English letter
}

/**
 * Flip the case of an English character.
 *
 * @param c - char type
 * @return -  c's upper/lower case letter if c is a lower/upper case English letter.
 */
char case_flip(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 32;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return c + 32;
    }
    return c; // <- returning c if it's not a letter
}

/**
 * Convert digit character to the corresponding integer value.
 *
 * @param c - char type value
 * @return - its corresponding integer value if c is a digit character;
 *           otherwise -1.
 */
int digit_to_int(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0'; // minus zero makes sense in this context because if essentially evens the playing filed and
        // tells the computer that we're dealing with ASCII and to treat it as such (normalizes it)
    }
    return -1;
}