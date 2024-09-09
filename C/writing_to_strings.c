#include <stdio.h>

int main(){

    char str[] = "L25";
    char ch;
    int num;

    sscanf(str, "%c%d", &ch, &num);
    printf("Extracted %c and %d\n", ch, num);

    char newstr[10];
    sprintf(newstr, "%d.%c", num, ch);
    printf("newstr formatting: '%s' \n", newstr);
    

    return 0;
}