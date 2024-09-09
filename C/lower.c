#include <stdio.h>

int main(){

    int low1 = 0, low2 = 0, low;
    int i = 0, t = 0;
    char str1[10];
    char str2[10];

    printf("Enter two strings:\n");
    scanf("%s", str1);
    scanf("%s", str2);
    while(str1[i] != '\0'){
        if(str1[i] >= 'a' && str1[i] <= 'z'){
            low1++;
        }
        i++;
    }
    
    while(str2[t] != '\0'){
        if(str2[t] >= 'a' && str2[t] <= 'z'){
            low2++;
            }
            t++;
        }
    if(low1 > low2){
        low = low1 - low2;
        printf("'%s' contains %d more lowercase letter(s) than '%s'.", str1, low, str2);
        
    }
    else if(low2 > low1){
        low = low2 - low1;
        printf("'%s' contains %d more lowercase letter(s) than '%s'.", str2, low, str1);
    }
    else if(low1 == 0 && low2 == 0){
        low = 0;
        printf("'%s' and '%s' both contain 0 lowercase letter(s).", str1, str2);
    }
    else if((low1 == low2) && (low1 > 0)){
        low = low1 - low2;
         printf("'%s' contains %d more lowercase letter(s) than '%s'.", str1, low, str2);
        
    }
    return 0;
}