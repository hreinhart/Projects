#include <stdio.h>

int main(){

    double scores0, scores1, scores2, scores3, scores4;
    double scores[5];
    int x0, x1, x2, x3, x4;
    int x[5];
    // int arr[] = { 10, 20, 30, 40 }
    printf("Enter 5 integers:\n");

    scanf("%d %d %d %d %d", &x0, &x1, &x2, &x3, &x4);
    x[0] = x0, x[1] = x1, x[2] = x2, x[3] = x3, x[4] = x4;

    //x[2]= (x[0]+ x[3]) /2;
    //x += 3 == x = x+3

    printf("x0 = %d\n", x0);
    printf("x1 = %d\n", x1);
    printf("x2 = %d\n", x2);
    printf("x3 = %d\n", x3);
    printf("x4 = %d\n", x4);

    printf("x[0] = %d\n", x[0]);
    printf("x[1] = %d\n", x[1]);
    printf("x[2] = %d\n", x[2]);
    printf("x[3] = %d\n", x[3]);
    printf("x[4] = %d\n", x[4]);





    return 0;
}
