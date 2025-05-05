#include <stdio.h>   // For standard input/output functions
#include <string.h>  // For string manipulation functions like strlen()
#include <ctype.h>   // For character classification functions like isupper(), islower(), and isdigit()

int main(int argc, char **argv) {
    // Check if the user provided a string as a command-line argument
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]); // Print usage instructions
        return 1; // Exit with an error code
    }

    char *word = *(argv + 1); // Pointer to the first command-line argument (the input string)
    int l = strlen(word);     // Get the length of the input string
    int up = 0;               // Counter for uppercase letters
    int low = 0;              // Counter for lowercase letters
    int dig = 0;              // Counter for digits

    // Loop through each character in the input string
    for (int i = 0; i < l; i++) {
        char c = *(word + i); // Get the character at position 'i'

        // Check if the character is an uppercase letter
        if (isupper(c)) {
            up++; // Increment the uppercase counter
        }
        // Check if the character is a lowercase letter
        else if (islower(c)) {
            low++; // Increment the lowercase counter
        }
        // Check if the character is a digit
        else if (isdigit(c)) {
            dig++; // Increment the digit counter
        }
    }

    // Print the results
    printf("Uppers = %d\n", up); // Print the count of uppercase letters
    printf("Lowers = %d\n", low); // Print the count of lowercase letters
    printf("Digits = %d\n", dig); // Print the count of digits

    return 0; // Exit the program
}