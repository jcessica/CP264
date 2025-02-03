/*
--------------------------------------------------
Project: a3 q1
File:   mystring.c
Author:  Jessica Desmond
Version: 2025-01-31
--------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include "mystring.h"

/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.  
 *
 * @param s - char pointer to a string
 * @return - return the number of words. 
 */
int str_words(char *s) {

    int count = 0;
    int in_word = 0;
    char *p = s;

    while (*p) {
        if ((*p >= 'a' && *s <= 'z') || (*p >= 'A' && *p <= 'Z')) 
        {
            if (!in_word) 
            {
                count ++;
                in_word = 1;
            }
        }
        else if (*p == ' ' || *p == '\t' || *p == ',' || *p == '.')
        {
            in_word = 0;
        }
        p ++;
    }

    return count;
}

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a string
 * @return - return the number of actual flips.   
 */
int str_lower(char *s) {
    int flips = 0;

    char *p = s;
    while (*p) {
        if ((*p >= 'A') && (*p <= 'Z'))
        {
            *p = *p + 32;
            flips++;
        }
        p++;
    }

    return flips;
}

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a string
 */
void str_trim(char *s) {
    char *p = s, *dp = s;

    while (*p) {

        if (*p != ' ' || (p > s && *(p-1) != ' '))
        {
            *dp = *p;
            dp++;
        }
        p++;
    }
    if (dp > s && *(dp - 1) == ' ')
    {
        *(dp - 1) = '\0';
    }
    else
    {
        *dp = '\0';
    }
}

