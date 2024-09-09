#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
int i =0;
int sum = 0;
char str[51];
int ar[26];
printf("Enter your input:\n");
scanf("%s", str);
while(!feof(stdin)){
for(i=0; i <= strlen(str); i++){
    int l =0;
    for(char lets = 'a'; lets <= 'z'; lets++){
        
        if(lets == str[i]){
            ar[l] = 1;
            
        }
        l++;
    }
}
scanf("%s", str);}
for(i=0; i<26; i++){
    sum = ar[i] + sum;}
if(sum / 26 > 0){printf("Your input contains all the letters");}
else{
    for(i=0; i< 26; i++){

    if(i==0){ printf("Missing letters: ");}
    if(ar[i] == 0){
        char b = i + 97;
        printf("%c ", b);
    }}}
return 0;
}