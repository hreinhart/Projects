#include <stdio.h>
#include <ctype.h>
#include <string.h>

int caps(char *str) {
   int c;
   for(int i = 0; i < strlen(str); i++)
   {
      if(str[i] >= 'A' && str[i] <= 'Z'){
         c++;
          }
}
return c;
}

int main(int argc, char *argv[]) {
   printf("%s has %d capital letters\n", argv[1], caps(argv[1]));
   
   return 0;
}
