#include <stdio.h>   // For standard input/output functions
#include <stdlib.h>  // For memory allocation and random number generation
#include <time.h>    // For seeding the random number generator with the current time

// Function prototypes
int **alloc2D(int rows, int cols); // Allocates memory for a 2D array
void initRand2D(int **arr, int rows, int cols); // Initializes the 2D array with random values
void print2D(int **arr, int rows, int cols); // Prints the 2D array
void free2D(int **arr, int rows); // Frees the memory allocated for the 2D array
int sum2D(int **arr, int rows, int cols); // Calculates the sum of all elements in the 2D array
double avg2D(int **arr, int rows, int cols); // Calculates the average of all elements in the 2D array
void minMax2D(int **arr, int rows, int cols, int *refMin, int *refMax); // Finds the minimum and maximum values in the 2D array

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int rows = 4, cols = 6; // Define the number of rows and columns for the 2D array
    int **arr = alloc2D(rows, cols); // Allocate memory for the 2D array
    initRand2D(arr, rows, cols); // Initialize the array with random values
    print2D(arr, rows, cols); // Print the array

    // Uncomment the following lines to calculate and display the sum and average of the array
    // printf("The sum is: %d\n", sum2D(arr, rows, cols));
    // printf("The avg is: %lf\n", avg2D(arr, rows, cols));

    int min, max;
    minMax2D(arr, rows, cols, &min, &max); // Find the minimum and maximum values in the array
    
    // Uncomment the following lines to display the minimum and maximum values
    // printf("The min is: %d\n", min);
    // printf("The max is: %d\n", max);

    free2D(arr, rows); // Free the memory allocated for the array

    return 0; // Exit the program
}

// Function to allocate memory for a 2D array
int **alloc2D(int rows, int cols) {
    int **array = (int **)malloc(rows * sizeof(int *)); // Allocate memory for row pointers
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int)); // Allocate memory for each row
    }
    return array; // Return the pointer to the 2D array
}

// Function to free the memory allocated for a 2D array
void free2D(int **arr, int rows) {
    for (int r = 0; r < rows; r++) {
        free(arr[r]); // Free each row
    }
    free(arr); // Free the array of row pointers
}

// Function to initialize a 2D array with random values
void initRand2D(int **arr, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) { // Loop through each element
            arr[r][c] = rand() % 100; // Assign a random value between 0 and 99
        }
    }
}

// Function to print a 2D array
void print2D(int **arr, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) { // Loop through each element
            printf("%d\t", arr[r][c]); // Print the element with a tab space
        }
        printf("\n"); // Print a newline after each row
    }
}

// Function to calculate the sum of all elements in a 2D array
int sum2D(int **arr, int rows, int cols) {
    int sum = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) { // Loop through each element
            sum += arr[r][c]; // Add the element to the sum
        }
    }
    return sum; // Return the total sum
}

// Function to calculate the average of all elements in a 2D array
double avg2D(int **arr, int rows, int cols) {
    int sum = sum2D(arr, rows, cols); // Calculate the sum of the array
    int numEle = rows * cols; // Calculate the total number of elements
    return (double)sum / numEle; // Return the average as a double
}

// Function to find the minimum and maximum values in a 2D array
void minMax2D(int **arr, int rows, int cols, int *refMin, int *refMax) {
    int min = arr[0][0]; // Initialize the minimum value
    int max = arr[0][0]; // Initialize the maximum value
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) { // Loop through each element
            int val = arr[r][c];
            if (val < min) { // Update the minimum value if necessary
                min = val;
            }
            if (val > max) { // Update the maximum value if necessary
                max = val;
            }
        }
    }
    *refMin = min; // Store the minimum value in the reference variable
    *refMax = max; // Store the maximum value in the reference variable
}