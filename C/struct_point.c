#include <stdio.h>
#include <math.h>

// function signature
// return-type name(formal_parameter1, formal_parameter2, ...);
double dist (int p1x, int p1y, int p2x, int p2y);

int main() {

    int p1x, p1y, p2x, p2y;
    printf("Enter an x and a y for point 1:\n");
    scanf("%d%d", &p1x, &p1y);
    printf("Enter an x and a y for point 2:\n");
    scanf("%d%d", &p2x, &p2y);


    double d = dist (p1x, p1y, p2x, p2y);
    printf("The distance between the points is %.2lf\n", d);

    return 0;
}

// function definition
// return-type name(params) { statements(s); }
double dist (int p1x, int p1y, int p2x, int p2y){
    int xVal = p2x - p1x;
    int yVal = p2y - p1y;
    double dist = sqrt ((xVal * xVal) + (yVal * yVal));


    return dist;

}