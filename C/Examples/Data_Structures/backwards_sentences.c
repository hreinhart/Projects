// This program reverses the characters in a word entered by the user until the user types "Done", "done", or "d".

#include <stdio.h>   // For standard input/output functions
#include <string.h>  // For string manipulation functions like strcmp() and strlen()

int main(void) {
    char word[50]; // Array to store the input word (up to 49 characters + null terminator)

    // Prompt the user to enter a word or sentence
    printf("Enter a word (type 'Done', 'done', or 'd' to exit):\n");
    scanf("%[^\n]%*c", word); // Read a line of input, including spaces, until a newline is encountered

    // Continue processing words until the user enters "Done", "done", or "d"
    while (strcmp(word, "Done") != 0 && strcmp(word, "done") != 0 && strcmp(word, "d") != 0) {
        int front = 0;              // Index pointing to the start of the word
        int len = strlen(word);     // Length of the word
        int back = len - 1;         // Index pointing to the end of the word

        // Reverse the word by swapping characters from the front and back
        while (front < back) {
            char ch = word[front];  // Temporarily store the character at the front
            word[front] = word[back]; // Replace the front character with the back character
            word[back] = ch;        // Replace the back character with the stored front character

            front++; // Move the front index forward
            back--;  // Move the back index backward
        }

        // Print the reversed word
        printf("Reversed word: %s\n", word);

        // Prompt the user to enter another word
        printf("Enter another word (type 'Done', 'done', or 'd' to exit):\n");
        scanf("%s", word); // Read the next word (up to the first space or newline)
    }

    printf("Program exited.\n"); // Indicate that the program has ended
    return 0; // Exit the program
}