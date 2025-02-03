/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_integers(void) {

    int num = 0;
    int tally = 0;
    int condition = 1;

    char input[STRING_BIG];

    printf("Enter integers, one per line:\n");

    while (condition) {

        if (fgets(input, sizeof(input), stdin) != NULL) 
        {
            if (sscanf(input,"%d", &num) == 1)
            {
                tally += num;
            }
            else 
            {
                condition = 0;
            }
        }
    }

    return tally;

}

