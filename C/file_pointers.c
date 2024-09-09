#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

FILE *fp;
fp = fopen("Yee", "w");
fprintf(fp, "This shit will be cool\n");
fclose(fp);

char word[100];
fp = fopen("Yee", "r");
fscanf(fp, "%s", word);
fprintf(stdout, "First string is: '%s'\n", word);
fclose(fp);

    return 0;
}