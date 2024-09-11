#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv){
    char *word = *(argv + 1);
    int l = strlen(word);
    int up = 0;
    int low = 0;
    int dig = 0;
    for(int i = 0; i < l; i++){
        char c = *(word + i); // Make sure to always do it like this.
        if(isupper(c)){
            up++;
        }
        else if(islower(c)){
            low++;
        }
        else if(isdigit(c)){
            dig++;
        }
    }
printf("Uppers = %d\n", up);
printf("Lowers = %d\n", low);
printf("Digits = %d\n", dig);



    return 0;
}
