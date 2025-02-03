/*
--------------------------------------------------
Project: a1q3
File:    quadratic.c
Author:  Jessica Desmond
Version: 2025-01-14
--------------------------------------------------
*/
#include "quadratic.h"
#include <math.h>

#define EPSILON 1e-6


/**
 * Compute and return solution type of given quadratic equation ax*x + bx + c = 0
 *
 * @param a  - quadratic coefficient
 * @param b  - linear coefficient
 * @param c - constant coefficient
 * @return - 0 if not quadratic equation, i.e. a=0;
 *           1 for one unique real solution;
 *           2 for two distinct real solutions;
 *           3 for two complex solutiions
 */

int solution_type(float a, float b, float c)
{
    int t = -1;
    float discrm = (b*b) - 4*(a*c)  ; // discriminant, for squaring in c use b*b
    if (fabs(a) < EPSILON){ /*fabs returns absolute positive value, the < Epsilon comparison 
 checks if a number is close enough to zero to basically be considered zero*/
 //if a is approximately 0, not a quad func
        t = 0;
}

    else{
        if(fabs(discrm) < EPSILON){
            t = 1;
        }
        else if (discrm > 0){
            t = 2;
        }
        else{
            t = 3;
        }
    }

    return t;
}


/**
 * Compute and return unique or bigger real roots of given quadratic equation ax*x + bx + c = 0 of types 1 and 2.
 * @param a  - quadratic coefficient
 * @param b  - linear coefficient 
 * @param c - constant coefficient
 * @return - the unique real root or the bigger real root if the quadratic equation has two distinct real roots 
             Ohterwise, return 0.
 */

float real_root_big(float a, float b, float c)
{
    int sol = solution_type(a,b,c);
    if (sol == 1||sol == 2){
        float roots1 = (-b + sqrt(b*b - 4*(a*c)))/(2*a);
        float roots2 = (-b - sqrt(b*b - 4*(a*c)))/(2*a);
        if (roots1 >= roots2){//coulda made it a one liner
            return roots1;
        }
        else{
            return roots2;
        }
    }
    else{
        return 0;
    }
// call solution_type to determine solution type, procede if the equation has real solutions. 
}

/**
 * Compute and return unique or smaller real roots of given quadratic equation ax*x + bx + c = 0 of types 1 and 2.
 * @param a  - quadratic coefficient
 * @param b  - linear coefficient 
 * @param c - constant coefficient
 * @return - 0 if not a == 0
             1 if having two complex solutions
             2 if            the unique real root or the smaller real root if the quadratic equation has two distinct real roots 
             Ohterwise, return 0.
 */
float real_root_small(float a, float b, float c)
{
    int sol = solution_type(a,b,c);

    if (sol == 0){
        return 0;
    }
    else if (sol == 3){
        return 0;
    }
    else if (sol == 1||sol == 2){
        float roots1 = (-b + sqrt(b*b - 4*(a*c)))/(2*a);
        float roots2 = (-b - sqrt(b*b - 4*(a*c)))/(2*a);
        if (roots1 <= roots2){
            return roots1;
        }
        else{
            return roots2;
        }
    }
    return 0;

}