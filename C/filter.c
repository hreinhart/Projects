#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

char c[51];
int i;
int j = 0;
FILE *fp;
FILE *fp2;
fp = fopen(argv[1], "r");
if (fp == NULL)
    {
     printf("Cannot open file '%s'", argv[1]);
     return 0;
    }
fp2 = fopen(argv[2], "w");

if (fp2 == NULL)
    {
     printf("Cannot open file '%s'", argv[2]);
     return 0;
    }
while(1){
    i =0;
    j =0;
    if(feof(fp)){
        fclose(fp);
        fclose(fp2);
        break; }
        fscanf(fp, "%s", c); 
    while(1){
        i++;
        if(isalpha(c[i])){         
            j++;
        }
        if(j == strlen(c)-1){
            fprintf(fp2,"%s ", c);}
        if(i == strlen(c)-1){
            break;
        }
    }
   }


    return 0;
}