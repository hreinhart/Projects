#include <stdio.h>   // For standard input/output functions
#include <ctype.h>   // For character classification functions like isupper() and islower()
#include <string.h>  // For string manipulation functions like strlen()

// Function prototype for countCase
void countCase(char str[], int *pNumUpper, int *pNumLower);

int main() {
    char str[50];       // Array to store the input string (up to 49 characters + null terminator)
    int pNumUpper = 0;  // Variable to store the count of uppercase letters
    int pNumLower = 0;  // Variable to store the count of lowercase letters

    // Read the first string from standard input
    scanf("%s", str);

    // Loop until the end of input (CTRL+D or EOF)
    while (!feof(stdin)) {
        // Call the countCase function to count uppercase and lowercase letters
        countCase(str, &pNumUpper, &pNumLower);

        // Print the results for the current string
        printf("%s: %d uppercase, %d lowercase\n", str, pNumUpper, pNumLower);

        // Read the next string from standard input
        scanf("%s", str);
    }

    return 0; // Exit the program
}

// Function to count uppercase and lowercase letters in a string
void countCase(char str[], int *pNumUpper, int *pNumLower) {
    *pNumLower = 0; // Initialize the lowercase count to 0
    *pNumUpper = 0; // Initialize the uppercase count to 0

    // Loop through each character in the string
    for (int i = 0; i < strlen(str); i++) {
        if (isupper(str[i])) { // Check if the character is uppercase
            (*pNumUpper)++;    // Increment the uppercase count
        } else if (islower(str[i])) { // Check if the character is lowercase
            (*pNumLower)++;    // Increment the lowercase count
        }
    }

    // The return statement is unnecessary here and should be removed
    // Remove the following line to fix the issue:
    // return countCase;
}