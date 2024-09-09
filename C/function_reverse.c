#include <stdio.h>
#include <string.h>

void reverse (char word[]); //str

int main() {

char word[50];
printf("Enter a word:\n");
scanf("%s", word);

//function call
reverse(word);

printf("The reversed word is: %s\n", word);

    return 0;
}

void reverse (char word[]){
    int l = strlen(word);

   /* for( int i = 0; i < l/2; i++){
        printf("Swapping %d and %d \n", i, len -1 -i);
        char ch = word[i];
        word[i] = word[len -1 -i];
        word[len -1 -i] = ch;
    }
}*/

int front = 0;
int back = l -1;
while(front<back){
    char ch = word[front];
    word[front] = word[back];
    word[back] = ch;

    front++;
    back--;
    }
}