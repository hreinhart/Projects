#include <stdio.h>
#include <string.h>

int main(){
int acount =0, ecount=0, icount=0, ocount=0, ucount=0;
char str[100];
int i = 0;
while(!feof(stdin)){
    gets(str);
        while(i < strlen(str)){
            if((str[i] == 'a') || (str[i] == 'A')){
                acount++;
        
    }
            else if ((str[i] == 'e') || (str[i] == 'E')){
                ecount++;
        
    }
            else if ((str[i] == 'i')||(str[i] == 'I')){
                icount++;
        
    }
            else if ((str[i] == 'o')||(str[i] == 'O')){
                ocount++;
        
    }
            else if ((str[i] == 'u')||(str[i] == 'U')){
                ucount++;
        
    }
    
            i++;
    
}}

printf("The vowel a occurred %d times\n", acount);
printf("The vowel e occurred %d times\n", ecount);
printf("The vowel i occurred %d times\n", icount);
printf("The vowel o occurred %d times\n", ocount);
printf("The vowel u occurred %d times\n", ucount);
    return 0;
}