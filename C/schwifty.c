#include <stdio.h>
#include <string.h>
#include <ctype.h>

void left(char word[]);
void right(char word[]);
void inc(char word[]);
void dec(char word[]);

int main(int argc, char **argv) {
if(argc != 3){
   printf("Invalid number of arguments\n");
   return 0;
}
char word[50];
FILE *fp;
fp = fopen(argv[1], "r");
if(fp == NULL){
   printf("Could not open file '%s'\n", argv[1]);
   return 0; }
for(int i = 0; i < strlen(argv[2]); i++){
   if(argv[2][i] == 'L' || argv[2][i] == 'R' || argv[2][i] == 'I' || argv[2][i] == 'D'){}
   else{
      printf("You threw off my schwiftiness with schwifty '%c'!", argv[2][i]);
      return 0; }
}
fscanf(fp, "%s", word);
while(!feof(fp)){
   for(int i = 0; i < strlen(argv[2]); i++){
      if(argv[2][i] == 'L'){
         left(word);
      }
      if(argv[2][i] == 'R'){
         right(word);
      }
      if(argv[2][i] == 'I'){
         inc(word);
      }
      if(argv[2][i] == 'D'){
         dec(word);
      }
   }
   printf("%s\n", word);
   fscanf(fp, "%s", word);
}
fclose(fp);
   return 0;
}

void left(char word[]) {
   char temp = word[0];
   int l = strlen(word) - 1;
   for(int i = 0; i < l; i++){
      word[i] = word[i + 1];
   }
   word[l] = temp;
}

void right(char word[]) {
   int l = strlen(word) - 1;
   char temp = word[l];
   for(int i = l; i > 0; i--){
      word[i] = word[i-1];
   }
   word[0] = temp;
}

void inc(char word[]) {
   int l = strlen(word);
   char let;
   for(int i = 0; i < l; i++){
      if(isdigit(word[i]) && word[i] != '9'){
      let = word[i] + 1;
      word[i] = let;}
      else if(isupper(word[i]) && word[i] != 'Z'){
         let = word[i] + 1;
         word[i] = let;
      }
      else if(islower(word[i]) && word[i] != 'z'){
         let = word[i] + 1;
         word[i] = let;
      }
      else if(word[i] == 'Z'){
         word[i] = 'A';}
      else if(word[i] == 'z'){
         word[i] = 'a';}
      else if(word[i] == '9'){
         word[i] = '0';
      }
      else{
         word[i] = word[i];
      }
   }
   
}

void dec(char word[]) {
    int l = strlen(word);
   char let;
   for(int i = 0; i < l; i++){
      if(isdigit(word[i]) && word[i] != '0'){
      let = word[i] - 1;
      word[i] = let;}
      else if(isupper(word[i]) && word[i] != 'A'){
         let = word[i] - 1;
         word[i] = let;
      }
      else if(islower(word[i]) && word[i] != 'a'){
         let = word[i] - 1;
         word[i] = let;
      }
      else if(word[i] == 'A'){
         word[i] = 'Z';}
      else if(word[i] == 'a'){
         word[i] = 'z';}
      else if(word[i] == '0'){
         word[i] = '9';
      }
      else{
         word[i] = word[i];
      }
   }
   
   
}
