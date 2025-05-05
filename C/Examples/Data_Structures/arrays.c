#include <stdio.h> // For standard input/output functions

int main() {
    // Declare variables for individual scores
    double scores0, scores1, scores2, scores3, scores4;

    // Declare an array to store 5 scores
    double scores[5];

    // Declare variables for individual integers
    int x0, x1, x2, x3, x4;

    // Declare an array to store 5 integers
    int x[5];

    // Prompt the user to enter 5 integers
    printf("Enter 5 integers:\n");

    // Read 5 integers from the user and store them in individual variables
    scanf("%d %d %d %d %d", &x0, &x1, &x2, &x3, &x4);

    // Assign the values from individual variables to the array
    x[0] = x0, x[1] = x1, x[2] = x2, x[3] = x3, x[4] = x4;

    // Uncomment the following line to calculate the average of x[0] and x[3] and store it in x[2]
    // x[2] = (x[0] + x[3]) / 2;

    // Uncomment the following line to demonstrate pointer arithmetic (not valid in this context)
    // x += 3 == x = x + 3;

    // Print the values of the individual variables
    printf("x0 = %d\n", x0);
    printf("x1 = %d\n", x1);
    printf("x2 = %d\n", x2);
    printf("x3 = %d\n", x3);
    printf("x4 = %d\n", x4);

    // Print the values stored in the array
    printf("x[0] = %d\n", x[0]);
    printf("x[1] = %d\n", x[1]);
    printf("x[2] = %d\n", x[2]);
    printf("x[3] = %d\n", x[3]);
    printf("x[4] = %d\n", x[4]);

    return 0; // Exit the program
}