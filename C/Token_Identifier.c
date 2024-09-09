#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {

int i = 0;
char token[50];
int sum =0;

printf("Enter a token to identify, EOF to stop:\n");
scanf("%s", token);



while(!feof(stdin)){
   int l = strlen(token);
   sum = 0;
   int g = 0;
   int ar[50] = {0};
   int z = 0;
   int e = 0;
   int m=0;
   int o =0;
   for(i=0; i < l; i++){
      if(isdigit(token[i])){
         if((token[i] == '0') || (token[i] == '1')) {
         ar[i] = 1;}
         else{ar[i] = 1;
         o++;
         }}
         
      else if(token[i] == '-' && (token[1] != '.')){
         ar[i] = 0;
         e++;
         }
      else if(token[i] == '.' && (i != 0)){
         ar[i] = 4;
         m++;}
      else if(token[i] >= 'A' && token[i] <= 'F'){
         ar[i] = 2;
         g = g + 1;
         }
      else if(token[i] >= 'a' && token[i] <='f'){
         ar[i] = 2;
         g = g + 1;
         }
      else{ ar[i] = -1;
      z++;
      }
      
   }
   
   for(int p =0; p < l; p++){
      sum = ar[p] + sum;}
   if((sum % l == 0) && (z==0) && (g == 0)&&(e==0)&&(m==0)){
      printf("The token is a positive integer\n"); }
   else if(((sum +1) % (l+g) == 0) && (z==0) && (g == 0)&&(e==1)&&(m==0)){
      printf("The token is a negative integer\n"); }
   else if(((sum + 4) % (l+g) == 0) && (token[8] == '-') && (token[13] == '-') && (token[18] == '-') && (token[23] == '-') && (z==0) && (e==4) && (m==0)) {
      printf("The token is a guid\n"); }
   else if(((sum - 3) % (l+g) == 0) && (z==0) && (g==0) && (e==0) && (m==1)){
               printf("The token is a positive floating-point number\n");}
   else if(((sum - 2) % (l+g) == 0) && (z == 0) && (token[0] == '-') && (g == 0)&&(e==1)&& (m==1)){
      printf("The token is a negative floating-point number\n");}
   else if(((sum) % (l+g) == 0) && (token[0] == '0') && (token[1] == 'b') && (l > 2) && (z==0) && (g == 1) &&(e==0) &&(m==0)&& (o==0)){
      printf("The token is a binary number\n");}
   else{
      printf("The token cannot be identified\n");}
   
printf("Enter a token to identify, EOF to stop:\n");
scanf("%s", token);}

   return 0;
}
