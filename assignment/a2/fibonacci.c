/*
 * your program signature
 */ 

#include "fibonacci.h"

/**
 * Cmpute and return the nth Fibonacci number F(n) using iterative algorithm, 
 *  namely using a for or while loop. 
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number 
 */
int recursive_fibonacci(int n) {
    if(n == 0){
        return 0; // no two numbers before 0
    }
    else if (n == 1){
        return 1;// only one number before 1
    }
    else {
        return (recursive_fibonacci(n-1) + recursive_fibonacci(n-2)); // Because each number is the sum of the two proceeding ones
    }

}
/**
 * Cmpute and return the nth Fibonacci number F(n) using iterative algorithm, 
 *  namely using a for or while loop. 
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number 
 */
int iterative_fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    int fib1 = 0, fib2 = 1, fibonacci = 0;

    for (int i = 2; i <= n; i++) {
        fibonacci = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibonacci;
    }

    return fibonacci;
}

/**
 * Compute and return the nth Fibonacci number F(n) using dynamic programming 
 * bottom-up method with an external array f[n+1] initialized to -1 for all elements. 
 *
 * @param f - the external array of size n+1
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number 
 */
int dpbu_fibonacci(int *f, int n) {
    f[0] = 0; // Base case
    f[1] = 1; // Base case

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

/**
 * Compute and return the nth Fibonacci number F(n) using dynamic programming 
 * top-down method with an external array f[n+1] initialized to -1 for all elements. 
 *
 * @param f - the external array of size n+1
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number 
 */
int dptd_fibonacci(int *f, int n) {
    if (f[n] != -1) {
        return f[n]; // Return cached result if available
    }

    if (n == 0) {
        f[n] = 0; // Base case
    } else if (n == 1) {
        f[n] = 1; // Base case
    } else {
        f[n] = dptd_fibonacci(f, n - 1) + dptd_fibonacci(f, n - 2);
    }

    return f[n];
}