#include <stdio.h>

int main() {
    
   double totalcost;
   int totalcents;
    int cupsleft, cbarsleft, bopopleft, bowatleft;
    int cupsneed, cbarsneed, bopopneed, bowatneed;
    double cupsavg, cbarsavg, bopopavg, bowatavg;
    double pcups = 0.05;
    double pcbars = 0.3;
    double pbopop = 0.2;
    double pbotwat = 0.5;

    printf ("Please enter the amount of remianing cups.\n");
    scanf("%d", &cupsleft);
    printf ("Now please enter the amount of candy bars remaining.\n");
    scanf("%d" , &cbarsleft);
    printf("Now enter the number of bags of popcorn remaining.\n");
    scanf("%d", &bopopleft);
    printf("Finally enter the amount of bottled water left.\n");
    scanf("%d", &bowatleft);

    cupsneed = 2000 - cupsleft;
    cbarsneed = 1000 - cbarsleft;
    bopopneed = 2500 - bopopleft;
    bowatneed = 750 - bowatleft;
    totalcost = (cupsneed * pcups) + (cbarsneed * pcbars) + (bopopneed * pbopop) + (bowatneed * pbotwat);
    cupsavg = cupsneed / 7.0;
    cbarsavg = cbarsneed / 7.0;
    bopopavg = bopopneed / 7.0;
    bowatavg = bowatneed /7.0;
    int totaldollars =  totalcost;
    int totalcostint = totalcost * 100;
    if (totalcost < 1){ totalcents = 0;} 

    else  {
        int totalcents = totalcostint % (totaldollars) 
        ;}
    

    printf("Need: %d cups, %d candy bars, %d bags of popcorn, and %d bottles of water.\n", cupsneed, cbarsneed, bopopneed, bowatneed);
    printf("Cost: %d dollars and %d cents.\n", totaldollars, totalcents);
    printf("Average sold: %.2lf cups, %.2lf candy bars, %.2lf bags of popcorn, and %.2lf bottles of water per day.\n", cupsavg, cbarsavg, bopopavg, bowatavg);
     
        return 0;
    }
