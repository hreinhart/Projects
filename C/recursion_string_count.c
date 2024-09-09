#include <stdio.h>


int length(char *str)   {
    int count = 0;
    char *ptr=str;
    while (*ptr != '\0') {
        count = count + 1;
        ptr++;
    }
    return count;
}


 
int main()
{
    int counter;
    char str_ch[50];
 
    printf("Enter string: ");
    scanf("%s", str_ch);
    counter = length(str_ch);
    printf("The number of characters in [ %s ] are %d.\n", str_ch, counter);
    return 0;
}
 #include <stdio.h>


int length(char *str)   {
    int count = 0;
    char *ptr=str;
    while (*ptr != '\0') {
        count = count + 1;
        ptr++;
    }
    return count;
}

/*
 
int main()
{
    int counter;
    char str_ch[50];
 
    printf("Enter string: ");
    scanf("%s", str_ch);
    counter = length(str_ch);
    printf("The number of characters in [ %s ] are %d.\n", str_ch, counter);
    return 0;
}
 */