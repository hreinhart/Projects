#include <stdio.h>   // For standard input/output functions
#include <string.h>  // For string manipulation functions like strlen()

int main() {
    int numwords;    // Variable to store the number of words the user will input
    int i = 0;       // Loop counter for iterating through the words
    int b = 0;       // Loop counter for iterating through the characters of a word
    char word[51];   // Array to store a single word (up to 50 characters + null terminator)

    // Prompt the user to enter the number of words
    printf("Enter how many words:\n");
    scanf("%d", &numwords); // Read the number of words from the user

    // Prompt the user to enter the words
    printf("Enter %d words:\n", numwords);
    printf("The result is '"); // Start the output for the result

    // Outer loop to process each word
    while (i < numwords) {
        scanf("%s", word); // Read a word from the user
        b = 0;             // Reset the character counter for the current word

        // Inner loop to process each character in the word
        while (b < strlen(word)) {
            // Check if the character is an uppercase letter (A-Z) but not 'Y'
            if (word[b] >= 'A' && word[b] <= 'Z' && word[b] != 'Y') {
                int c = word[b];  // Get the ASCII value of the character
                char let = c;     // Convert the ASCII value back to a character
                printf("%c", let); // Print the character
            }
            b++; // Move to the next character in the word
        }

        i++; // Move to the next word
    }

    printf("'\n"); // End the output for the result

    return 0; // Exit the program
}