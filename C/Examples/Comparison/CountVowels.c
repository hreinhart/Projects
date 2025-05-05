#include <stdio.h>   // For standard input/output functions
#include <string.h>  // For string manipulation functions like strlen()

int main() {
    // Initialize counters for each vowel
    int acount = 0, ecount = 0, icount = 0, ocount = 0, ucount = 0;

    char str[100]; // Array to store the input string (up to 99 characters + null terminator)
    int i = 0;     // Index for iterating through the characters of the string

    // Loop to read input until the end of the file (CTRL+D or EOF)
    while (!feof(stdin)) {
        gets(str); // Read a line of input (deprecated, consider using fgets instead)

        // Loop through each character in the string
        while (i < strlen(str)) {
            // Check if the character is 'a' or 'A'
            if ((str[i] == 'a') || (str[i] == 'A')) {
                acount++; // Increment the counter for 'a'
            }
            // Check if the character is 'e' or 'E'
            else if ((str[i] == 'e') || (str[i] == 'E')) {
                ecount++; // Increment the counter for 'e'
            }
            // Check if the character is 'i' or 'I'
            else if ((str[i] == 'i') || (str[i] == 'I')) {
                icount++; // Increment the counter for 'i'
            }
            // Check if the character is 'o' or 'O'
            else if ((str[i] == 'o') || (str[i] == 'O')) {
                ocount++; // Increment the counter for 'o'
            }
            // Check if the character is 'u' or 'U'
            else if ((str[i] == 'u') || (str[i] == 'U')) {
                ucount++; // Increment the counter for 'u'
            }

            i++; // Move to the next character in the string
        }
    }

    // Print the counts for each vowel
    printf("The vowel a occurred %d times\n", acount);
    printf("The vowel e occurred %d times\n", ecount);
    printf("The vowel i occurred %d times\n", icount);
    printf("The vowel o occurred %d times\n", ocount);
    printf("The vowel u occurred %d times\n", ucount);
    printf("The total number of vowels is %d\n", acount + ecount + icount + ocount + ucount);
    
    return 0; // Exit the program
}