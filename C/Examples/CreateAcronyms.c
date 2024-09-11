#include <stdio.h>
#include <string.h>
#include <ctype.h>

void CreateAcronym(char userPhrase[50], char userAcronym[10]){
   int licknuts = 0;
   for(int i = 0; i < strlen(userPhrase); i++){
      char ch = userPhrase[i];
      if(ch >= 'A' && ch <= 'Z'){
         userAcronym[licknuts] = ch;
         licknuts++;}}
   
   printf("%s\n", userAcronym);
}

int main(void) {
   char userAcronym[10];
   char userPhrase[50];
   scanf("%[^\n]%*c", userPhrase);
   CreateAcronym(userPhrase, userAcronym);
   

   return 0;
}
