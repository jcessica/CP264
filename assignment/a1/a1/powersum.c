/*
--------------------------------------------------
Project: a1q2
File:    powersum.c
Author:  Jessica Desmond
Version: 2025-01-14
--------------------------------------------------
*/

#include "powersum.h"

/**
 * Detect if overflow in power computing of b to power of n  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - 1 if overflow happens, 0 otherwise
 */

int power_overflow(int b, int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++) {
        int temp = p * b; // Since we're working up the chain with powers of b, we start with the initial power of b; 1.
        if (temp/ b != p) { 

            /* Ideally w/ no overflow temp/b = p because p is the last saved power of b that we multiplied w/ b.
             If temp/b is not equal to p, then it means we've encountered an overflow, meaning the number was so large it 
            wrapped around, changing the value of p*b.*/

            return 1; //overflow detected
        }
        p = temp; // Saves last calculated power of b to then be multiplied by b at the next iteration
    }
    return 0;  // No overflow.


}

/**
 * Compute and return b to power of n.  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - b to the power of n if no overflow happens, 0 otherwise
 */
int mypower(int b, int n)
{
    int p = 1;

    for (int i = 1; i<=n;i++) {
        int temp = p * b;
        if (temp/b != p) {
            return 0; //Overflow detected
        }
        p = temp; // Saves last calculated power of b

    }
    return p; //Final iteration p = b^n if no overflow


}


/**
 * Compute and return the sum of powers.
 *
 * @param b - the base
 * @param n - the exponent
 * @return -  the sum of powers if no overflow happens, 0 otherwise 
 */
int powersum(int b, int n)
{ 
    int p = 1;
    int sums = 1;

    for (int i = 1; i <= n; i++){
        int temp = p*b;
        if (temp/b != p){
            return 0;
        }
        sums += temp;
        p = temp;

    }
    return sums;


}