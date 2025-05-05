#include <stdio.h> // For standard input/output functions

int main() {
    // Declare variables for total cost and total cents
    double totalcost; // Total cost of items needed
    int totalcents;   // Total cost in cents

    // Declare variables for remaining stock and needed stock
    int cupsleft, cbarsleft, bopopleft, bowatleft; // Remaining stock of cups, candy bars, popcorn, and bottled water
    int cupsneed, cbarsneed, bopopneed, bowatneed; // Stock needed for cups, candy bars, popcorn, and bottled water

    // Declare variables for average daily sales
    double cupsavg, cbarsavg, bopopavg, bowatavg;

    // Declare prices for each item
    double pcups = 0.05;   // Price per cup
    double pcbars = 0.3;   // Price per candy bar
    double pbopop = 0.2;   // Price per bag of popcorn
    double pbotwat = 0.5;  // Price per bottle of water

    // Prompt the user to enter the remaining stock for each item
    printf("Please enter the amount of remaining cups.\n");
    scanf("%d", &cupsleft);
    printf("Now please enter the amount of candy bars remaining.\n");
    scanf("%d", &cbarsleft);
    printf("Now enter the number of bags of popcorn remaining.\n");
    scanf("%d", &bopopleft);
    printf("Finally enter the amount of bottled water left.\n");
    scanf("%d", &bowatleft);

    // Calculate the stock needed for each item
    cupsneed = 2000 - cupsleft;    // Cups needed to reach 2000
    cbarsneed = 1000 - cbarsleft;  // Candy bars needed to reach 1000
    bopopneed = 2500 - bopopleft;  // Bags of popcorn needed to reach 2500
    bowatneed = 750 - bowatleft;   // Bottles of water needed to reach 750

    // Calculate the total cost of the needed stock
    totalcost = (cupsneed * pcups) + (cbarsneed * pcbars) + (bopopneed * pbopop) + (bowatneed * pbotwat);

    // Calculate the average daily sales for each item (assuming a 7-day week)
    cupsavg = cupsneed / 7.0;
    cbarsavg = cbarsneed / 7.0;
    bopopavg = bopopneed / 7.0;
    bowatavg = bowatneed / 7.0;

    // Calculate the total cost in dollars and cents
    int totaldollars = totalcost; // Extract the dollar portion of the total cost
    int totalcostint = totalcost * 100; // Convert total cost to cents
    if (totalcost < 1) {
        totalcents = 0; // If the total cost is less than 1 dollar, set cents to 0
    } else {
        totalcents = totalcostint % (totaldollars * 100); // Calculate the cents portion
    }

    // Display the results
    printf("Need: %d cups, %d candy bars, %d bags of popcorn, and %d bottles of water.\n", cupsneed, cbarsneed, bopopneed, bowatneed);
    printf("Cost: %d dollars and %d cents.\n", totaldollars, totalcents);
    printf("Average sold: %.2lf cups, %.2lf candy bars, %.2lf bags of popcorn, and %.2lf bottles of water per day.\n", cupsavg, cbarsavg, bopopavg, bowatavg);

    return 0; // Exit the program
}