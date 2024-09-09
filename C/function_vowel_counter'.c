#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count (char word[]){
    int counter = 0;
}

int main(){

char word[50];
printf("Enter word for vowel count:\n");
scanf("%s" , word);

int vowelCount = count(word);

printf("The number of vowels in string: %d\n", vowelCount);




    return 0;
}

int count (char word[]){
    int counter = 0;

    for(int i = 0; i < strlen(word); i++){
        char ch = toupper (word[i]);
        if( ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            counter++;
        }
    }
    return counter;
}