/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"


void int_array_read(int *array, int size) {

    // your code here
    int num, count = 0; //Setting both num and count to 0
    int condition = 1; // Using condition like a switch to break out of the loop
    char input[STRING_BIG];// STR_BIG is a constant allowing for up to 1024 characters

    printf("Enter %d values for an array of int.\n", size); // <- Imagine this is 
    /* <- Num is like the bucket you want to fill, the & symbol is telling the
    person where the bucket you want to fill is. Without the & sign there is no indicated memory address and it's
    like telling someone to fill a bucket without telling them where */
    
    while (condition && count < size) { // Checking our switch condition, and making sure we have enough slots to accomodate the numbers
        
        printf("Value for index %d: ", count);

        if (fgets(input, sizeof(input), stdin) != NULL) {
        //fgets() <- Std lib func in c used to read a string from a file or input stream
        //input <- aka "buffer" , where the character array will be stored
        //sizeof() <- specifies the size of the buffer to prevent buffer overflow
        //stdin <- specifes where we're getting the input from 

        //The above live of code basically says, "if we get any input", continue

        
        // if we get a keyboard input 
        
            int result = sscanf(input, "%d", &num); 

            //sscan reads from a string alr in memory (input)
            // determines the format of the integer we want, ignores everything afterwards

            //Its syntax: int sscanf(const char *str, const char *format, ...);
            // const char *str <- The string to read from 
            //"%d" <- how to interpret the data
            //... <- where the data is stored

            //sscan() <- returns the number of items successfully parsed, in this case with the specifications made, it's either 1 or 0, 
            //if it's 1 then we add that item to our array 
            //updating our array so that the 'i'th number input gets placed at the 'i'th number index
            if (result == 1){ 
                array[count] = num; 
                count++;
            }
            else {
                printf("Not a valid integer\n");
                }
            
        }
        else {
            condition = 0; // With no input, our switch turns off, hence breaking the loop!
        }
    }
}
