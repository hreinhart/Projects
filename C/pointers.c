#include <stdio.h>

int main(){

    int x = 3, y = 4, z =5;
    printf("Value of variable x is : %d and the address of x is: %p\n", x, &x);
    printf("Value of variable y is : %d and the address of y is: %p\n", y, &y);
    printf("Value of variable z is : %d and the address of z is: %p\n", z, &z);

    int *num1;
    double *num2;
    char *char3;

    int *a, *b, *c;
    a = &x;
    b = &y;
    c = &z;

    printf("x = %d, &x = %p, a = %p, *a = %d\n", x, &x, a, *a);
    printf("y = %d, &y = %p, b = %p, *b = %d\n", y, &y, b, *b);
    printf("z = %d, &z = %p, c = %p, *c = %d\n", z, &z, c, *c);

    //Arrays - natual use of pointers
    //Array name- pointer to the syart of the array
    
    int arr[3] = {101, 234, 999};
    int *p1, * p2;
    p1 = arr; //&arr[0]; = 101
    p2 = arr + 2; //&arr[2]; = 999
    printf("%d and %d and %d\n", arr[0], arr[1], arr[2]);
    printf("%p and %p\n", arr, &arr[0]);
    printf("%d = %p | %d = %p\n", arr[0], &arr[0], *p1, p1);
    printf("%d = %p | %d = %p\n", arr[1], &arr[1], *(arr+1), arr+1);
     printf("%d = %p | %d = %p\n", arr[2], &arr[2], *p2, p2);

    return 0;
}