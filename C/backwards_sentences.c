// scanf ("%[^\n]%*c", ch); This is to scan a sentence.

#include <stdio.h>
#include <string.h>

int main(void) {
   
   char word[50];
   scanf("%[^\n]%*c", word);
   
   while(strcmp(word, "Done") != 0  && strcmp(word, "done") != 0 && strcmp(word, "d") != 0){
      int front = 0;
      int len = strlen(word);
int back = len -1;
while(front<back){
    char ch = word[front];
    word[front] = word[back];
    word[back] = ch;

    front++;
    back--;
   
   }
   printf("%s", word);
   printf("\n");
   scanf("%s", word);
   }
