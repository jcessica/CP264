/*
--------------------------------------------------
Project: a3 q2
File:   myword.c
Author:  Jessica Desmond
Version: 2025-01-31
--------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"
#include "mystring.c"

#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000


/*
 * Load word data from file, and insert words a directory represented by char array.
 * 
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored. 
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.   
 */
int create_dictionary(FILE *fp, char *dictionary) {
    char line[MAX_LINE_LEN];
    char delimeters[] = ".,\n\t\r";
    char *token;
    int count = 0;

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        
        token = strtok(line, delimeters);

        while (token != NULL) {
            str_lower(token);
            str_trim(token);

            strcat(dictionary, token);
            strcat(dictionary, ",");

            count++;

            token = (char*) strtok(NULL, delimeters);
        }

    }
    if (count > 0) 
    {
        int len = strlen(dictionary);
        if (len > 0 && dictionary[len-1] == ',') {
            dictionary[len-1] = '\0';
        }
    }

    return count;
}

/*
 * Determine if a given word is contained in the given dictionary.  
 * 
 * @param *dictionary -  char pointer to a char array of given dictionary.
 * @param *word  -  pointer to a given word.  
 *                     
 * @return - TRUE if the word is in the dictionary, FALSE otherwise.   
 */
BOOLEAN contain_word(char *dictionary, char *word) {
    BOOLEAN contains = FALSE;
    if (word == NULL || *word == '\0')
    {
        return contains;
    }
    
    char temp[20] = {0};
    strcat(temp, ",");
    strcat(temp, word);
    strcat(temp, ",");
    if (strstr(dictionary, temp) != NULL) 
    {
        contains = TRUE; 
    }
    
    return contains;
}

/*
 * Process text data from a file for word statistic information of line count, word count, keyword count, and frequency of keyword.   
 * 
 * @param *fp -  FILE pointer of input text data file. .
 * @param *words  -  WORD array for keywords and their frequencies.
 * @param *dictionary  -  stop-word/common-word dictionary.    
 *                     
 * @return - WORDSTATS value of processed word stats information.   
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary) {
    
    WORDSTATS ws = { 0 };
    int word_index;
    char line[MAX_LINE_LEN];
    char delimeters[] = " .,\n\t\r";
    char *word_token;

    while (fgets(line, MAX_LINE_LEN, fp) != NULL) 
    {
        ws.line_count++;
        str_lower(line);

        word_token = (char*) strtok(line, delimeters);
        while (word_token != NULL) 
        {
            ws.word_count++;   
            if (contain_word(dictionary, word_token) != FALSE) 
            {
                int j = 0;
                while (j < ws.keyword_count && strcmp(word_token, words[j].word)!= 0) 
                {
                    j++;
                }
                if (j < ws.keyword_count)
                {
                    words[j].count++;
                }
                else
                {
                    strcpy(words[j].word, word_token);
                    words[j].count = 1;
                    ws.keyword_count++;
                }
            
            }
            word_token = (char*) strtok(NULL, delimeters);
        }
    }
    fclose(fp);
    return ws;
}