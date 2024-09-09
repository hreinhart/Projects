#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Change reverse string to heap allocation and change function to return a reversed string
Original word will remain unchanged
*/

//char *reverse(char *str); //str[]  same as *str
void reverse(char *str); //str[]  same as *str

int main() {

    char word[50];
    printf("Enter a word:\n");
    scanf("%s", word);

    reverse(word);
    //char *revWord = reverse(word);

    printf("The reversed word is: %s\n", word);
    //printf("The reversed word is: %s\n", revWord);
    
    //free(revWord);
    return 0;
}
void reverse(char str[]) {  //*str
//char *reverse(char str[]) {  //*str
    //hello //olleh
    //world //dlrow
    
    int len = strlen(str);
    //char *revWord = (char*)malloc((len + 1) * sizeof(char));
    //strcpy(revWord, str);

    char *front = str;
    //char *front = revWord;
    char *back = str + len - 1;
    //char *back = revWord + len - 1;
    while (front < back) {
        char ch = *front;
        *front = *back;
        *back = ch;

        front++;
        back--;
    }
   //return revWord;
}
