#include <stdio.h>

int main(void) {

int num;
int i =0;
scanf("%d", &num);
   while(i < num){
      if(num %2 != 0){
         printf("1");}
         else{printf("0");}
         num = num /2;
   
   }
  

 printf("\n");
   return 0;
}
