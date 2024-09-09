#include <stdio.h>

int main(){

int a,b,c;

printf("Enter three integers:\n");
scanf("%d%d%d", &a, &b, &c);

int max = max3 (a,b,b);

printf("THe max of the three is %d\n", max);



    return 0;
}

int max3 (int a, int b, int c){
    if (a>= b && a >= c)
        return a;
    if (b >= c && b >=a)
        return b;
    return c;
}