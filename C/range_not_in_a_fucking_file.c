#include <stdio.h>
#include <stdlib.h>


int main(){

int big, small, num, range;

scanf("%d", &num);
big = small = num;
while(!feof(stdin)){

scanf("%d", &num);

    if(num > big){
        big = num;
    }
    if(num < small){
        small = num;
    }

}

range = big - small;

printf("Range of input = %d", abs(range));

    return 0;
}