#include <stdio.h>

void swap(int *x, int *y);

int main(){

int x =3;
int y =4;

printf("x = %d, y = %d \n", x, y);
//function call
swap (&x, &y);

printf("After swap: x = %d, y = %d\n",x ,y);

    return 0;
}

void swap (int *x, int *y){
    int tempX = *x;
    *x = *y;
    *y = tempX;
}
//Stars are called pass by. Need them to ignore original shit in beginning.
// Also have to use & signs to get address which you change.