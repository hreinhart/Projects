#include <stdio.h>
#include <math.h>


//double dist(int p1x, int p1y, int p2x, int p2y);


int main(){

int p1x, p2x, p1y, p2y;

printf("Enter x and y for point 1:\n");
scanf("%d%d", p1x, p1y );
printf("Enter x and y for point 2:\n");
scanf("%d%d", p2x, p2y);
// function signature
// return-type name(formal_parameter 1, formal_parameter2, ...);
double d = dist(p1x, p1y, p2x, p2y);
 
printf("The distance between the two points is: %.2l\n", d);

    return 0;
}

double dist(int p1x, int p1y, int p2x, int p2y){
    int xVal = (p2x - p1x);
    int yVal = (p2y -p2y);
    double distance = sqrt(((p2x -p1x) *(p2x -p1x)) +((p2y - p1y) *(p2y - p1y)));

    return distance;
}