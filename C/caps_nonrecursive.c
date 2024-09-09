#include <stdio.h>
#include <string.h>

int main(){

int numwords;
int i = 0;
int b = 0;
char word[51];
printf("Enter how many words:\n");
scanf("%d", &numwords);

printf("Enter %d words:\n", numwords);
printf("The result is '");
while (i<numwords){
    scanf("%s", word);
    b=0;
    while (b < strlen(word)){
            if(word[b] >= 'A' && word[b] <= 'Z' && word[b] != 'Y'){
                
                int c = word[b];
                char let = c;
                printf("%c", let);

            }


b++;}

i++;}
printf("'\n");


    return 0;
}