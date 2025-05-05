#include <stdio.h>   // For standard input/output functions
#include <ctype.h>   // For character classification functions like isupper()
#include <string.h>  // For string manipulation functions like strlen()

// Function to count the number of capital letters in a string
int caps(char *str) {
   int c = 0; // Initialize the counter for capital letters to 0

   // Loop through each character in the string
   for (int i = 0; i < strlen(str); i++) {
      // Check if the character is a capital letter (A-Z)
      if (str[i] >= 'A' && str[i] <= 'Z') {
         c++; // Increment the counter if the character is uppercase
      }
   }

   return c; // Return the total count of capital letters
}

int main(int argc, char *argv[]) {
   // Check if the user provided a string as a command-line argument
   if (argc < 2) {
      printf("Usage: %s <string>\n", argv[0]); // Print usage instructions
      return 1; // Exit with an error code
   }

   // Call the caps function and print the result
   printf("%s has %d capital letters\n", argv[1], caps(argv[1]));

   return 0; // Exit the program
}