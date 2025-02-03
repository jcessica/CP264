/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {

    // your code here
    int num1, num2, num3;
    int sum = 0;
    int checker = 1;
    char input[STRING_BIG];


    printf("Enter three comma-separated integers: ");



    while (checker) {
        if (fgets(input,sizeof(input),stdin) != NULL) {

            if (sscanf(input,"%d,%d,%d", &num1, &num2, &num3) == 3){
                sum = num1 + num2 + num3;
                checker = 0;
            }
            else {
                printf("The integers were not properly entered.\n");
                printf("Enter three comma-separated integers: ");
            }

        }
        else {
            checker = 0;
        }

    }

    return sum;
 
}
