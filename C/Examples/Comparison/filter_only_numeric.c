#include <stdio.h>   // For file operations and standard I/O
#include <ctype.h>   // For character classification functions like isalpha()
#include <string.h>  // For string manipulation functions like strlen()
#include <stdlib.h>  // For general utilities like memory allocation

int main(int argc, char *argv[]) {
    // Declare variables
    char c[51];       // Buffer to store a word (up to 50 characters + null terminator)
    int i;            // Index for iterating through characters in the word
    int j = 0;        // Counter for the number of alphabetic characters in the word
    FILE *fp;         // Pointer for the input file
    FILE *fp2;        // Pointer for the output file

    // Open the input file in read mode
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        // Print an error message if the input file cannot be opened
        printf("Cannot open file '%s'", argv[1]);
        return 0;
    }

    // Open the output file in write mode
    fp2 = fopen(argv[2], "w");
    if (fp2 == NULL) {
        // Print an error message if the output file cannot be opened
        printf("Cannot open file '%s'", argv[2]);
        return 0;
    }

    // Main loop to process the input file
    while (1) {
        i = 0;  // Reset character index
        j = 0;  // Reset alphabetic character counter

        // Check if the end of the file has been reached
        if (feof(fp)) {
            fclose(fp);  // Close the input file
            fclose(fp2); // Close the output file
            break;       // Exit the loop
        }

        // Read a word from the input file
        fscanf(fp, "%s", c);

        // Inner loop to process the characters in the word
        while (1) {
            i++; // Move to the next character

            // Check if the character is alphabetic
            if (isalpha(c[i])) {
                j++; // Increment the alphabetic character counter
            }

            // If all characters in the word are alphabetic, write the word to the output file
            if (j == strlen(c) - 1) {
                fprintf(fp2, "%s ", c);
            }

            // Break the loop if the end of the word is reached
            if (i == strlen(c) - 1) {
                break;
            }
        }
    }

    return 0; // Exit the program
}