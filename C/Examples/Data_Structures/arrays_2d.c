#include <stdio.h>   // For standard input/output functions
#include <stdlib.h>  // For memory allocation (if needed in future)

// Function to get an element from a 1D array using a continuous memory layout
int getElementContinuous(int x[], int pos) {
    return x[pos]; // Return the element at the specified position
}

// Function to get an element from a 2D array using row and column indices
int getElement(int x[][4], int row, int col) {
    return x[row][col]; // Return the element at the specified row and column
}

int main(void) {
    // Declare and initialize a 2D array with 6 rows and 4 columns
    int array1[6][4] = { 
                        {0, 1, 2, 3}, 
                        {4, 5, 6, 7},
                        {8, 9, 10, 11},
                        {12, 13, 14, 15},
                        {16, 17, 18, 19},
                        {20, 21, 22, 23}
                       };

    // Infinite loop to allow the user to repeatedly query elements in the array
    while (1) {
        printf("Enter two subscripts or CTRL-D to exit : "); // Prompt the user for row and column indices
        int row, col; // Variables to store the user-provided row and column indices
        scanf("%d%d", &row, &col); // Read the row and column indices from the user
        if (feof(stdin)) // Check if the user has entered CTRL-D (end of input)
            break; // Exit the loop if end of input is detected

        // Print the value at the specified row and column using direct array indexing
        printf("array1[%d][%d] is %d\n", row, col, array1[row][col]);

        /*
        // Alternative approach: Calculate the index in a continuous memory layout
        int index = 4 * row + col; // Calculate the 1D index for the 2D array
        int val = getElementContinuous((int *) array1, index); // Get the value using the 1D index
        printf("array1[%d] is %d\n", index, val);

        // Reverse calculation: Convert the 1D index back to row and column
        row = index / 6; // Calculate the row from the index
        col = index % 6; // Calculate the column from the index
        */

        // Print the value at the specified row and column using the `getElement` function
        printf("array1[%d][%d] is %d\n", row, col, getElement(array1, row, col));
    }

    return 0; // Exit the program
}