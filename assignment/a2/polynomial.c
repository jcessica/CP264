/*
 * Polynomial Solver
 */

#include <stdio.h>
#include <math.h>
#include "polynomial.h"
#define EPSILON 1e-6
#define MAXCOUNT 100

/**
 * Compute and return the value of the (n-1)-th degree polynomial
 * p(x) = p[0]*x^{n-1} +  p[1]*x^{n-2} +...+ p[n-2]*x^1 + p[n-1]*x^0
 * using Horner's algorithm.
 *
 * @param *p - pointer to float number array
 * @param n  - the number of coefficients   
 * @param x  - the value at which to evaluate the polynomial
 * @return - the value of the polynomial at x
 */
float horner(float *p, int n, float x)
{
    float result = p[0];
    for (int i = 1; i < n; i++) {
        result = result * x + p[i];
    }
    return result;
}

/**
 * Compute the derivative of input (n-1)-th degree polynomial
 * p(x) = p[0]*x^{n-1} +  p[1]*x^{n-2} +...+ p[n-2]*x^1 + p[n-1]*x^0 
 * Output the coefficients of the derivative polynomial in an array.
 *
 * @param *p - pointer to coefficient array of input polynomial.
 * @param *d - pointer to coefficient array of output polynomial. 
 * @param n  - the number of coefficients of the input polynomial
 */
void derivative(float *p, float *d, int n)
{
    for (int i = 0; i < n - 1; i++) {
        d[i] = (n - 1 - i) * p[i];
    }
}

/**
 * Return the absolute value of x.
 *
 * @param x - the input value
 * @return - the absolute value of x
 */
float myfabs(float x)
{
    return x < 0 ? -x : x;
}

/**
 * Compute approximate real root x of polynomial p(x) using Newton's 
 * method. Use fault tolerant 1e-6 and maximum 100 iterations.
 *
 * @param *p - pointer to coefficient array of input polynomial.
 * @param n  - the number of coefficients of the input polynomial
 * @param x0 - start point for Newton method
 * @return - the root if found, otherwise x0.
 */
float newton(float *p, int n, float x0)
{
    float x = x0;
    float d[MAXCOUNT];
    derivative(p, d, n);

    for (int i = 0; i < MAXCOUNT; i++) {
        float fx = horner(p, n, x);
        if (myfabs(fx) < EPSILON) {
            return x;
        }
        float fdx = horner(d, n - 1, x);
        if (myfabs(fdx) < EPSILON) {
            break; // Avoid division by zero
        }
        x -= fx / fdx;
    }
    return x0; // Return the initial value if no root is found
}
