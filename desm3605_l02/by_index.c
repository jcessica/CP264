/**
 * -------------------------------------
 * @file  by_index.c
 * Lab 2 Index Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "by_index.h"

/**
 * Populates values with consecutive integers in the range [1 to size].
 * Uses array indexing.
 *
 * @param values - array of int
 * @param size - size of values
 */
void fill_values_by_index(int values[], int size) { //function stub is just a place holder, this void function is a place
//holder 

    for(int i = 0; i < size; i++) {
        values[i] = i + 1;
    }
}


/**
 * Populates squares with the squares of the corresponding integers in values.
 * Uses array indexing.
 *
 * @param values - array of int
 * @param squares - array of int, each a square of corresponding int in values
 * @param size - size of values and squares
 */
void fill_squares_by_index(int values[], long int squares[], int size) {

    // why are we using long -> if the result is big
    for(int i = 0; i < size; i++){
        squares[i] = values[i]*values[i];

        //(squares) -> squares[0]

        //(squares+1) -> squares[1]
        

    }

}

/**
 * Prints the contents of values and squares in two columns.
 * Uses array indexing.
 *
 * @param values - array of int
 * @param squares - array of int, each a square of corresponding int in values
 * @param size - size of values
 */
void print_by_index(int values[], long int squares[], int size) {

    // your code here

    printf("Value  Square    ");
    printf("-----  ----------");
    for(int i = 0; i < size; i++) {
        printf("    %d,           %ld",values[i],squares[i]);//second % is ld because it's a long int
    }


}
