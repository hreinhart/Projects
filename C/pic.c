#include <stdio.h>

int main(){

int num;
int i =0;
int b =0;

scanf("%d", &num);

while(i < num){
     b=0;
    while(b < num){
        
        if((b == 0) || (b == num-1) || (i == 0) || (i == num-1)){
            printf("X");
            
        }
        else{
            printf(" ");
            
        }
        b++;
    }

i++;
printf("\n");
}







    return 0;
}