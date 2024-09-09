#include <stdio.h>
#include <ctype.h>
#include <string.h>

void countCase(char str[], int *pNumUpper, int *pNumLower);

int main(){
char str[50];
int pNumUpper = 0;
int pNumLower = 0;

scanf("%s", str);
while(!feof(stdin)){
countCase(str, &pNumUpper, &pNumLower);
    printf("%s: %d uppercase, %d lowercase\n", str, pNumUpper, pNumLower);
    scanf("%s", str);
}
    return 0;
}

void countCase(char str[], int *pNumUpper, int *pNumLower){
    *pNumLower = 0;
    *pNumUpper = 0;
    for(int i = 0; i < strlen(str); i++){
        if(isupper(str[i])){
            (*pNumUpper)++;
        }
        else if(islower(str[i])){
            (*pNumLower)++;
        }
    }
        return countCase;
}