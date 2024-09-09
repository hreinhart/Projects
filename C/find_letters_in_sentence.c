#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
   int fuck =0;
   char str[50];
   scanf("%[^\n]%*c", str);
   
   for(int i = 0; i < strlen(str); i++){
      char ch = toupper(str[i]);
      if(ch >= 'A' && ch <= 'Z'){
         fuck++;}}
   
   
   printf("%d\n", fuck);
   return 0;
}