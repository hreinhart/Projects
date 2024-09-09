#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
int num1, num2;
FILE *fp;
FILE *fp2;

fp= fopen(argv[1], "r");
fp2 = fopen(argv[2], "r");


fscanf(fp, "%d", &num1);
fscanf(fp2, "%d", &num2);
while(1){
    if(feof(fp) ||  feof(fp2)){
        break;
    }
    if(num1 < num2){
        printf("%d ", num1);
        fscanf(fp, "%d", &num1);
    }
    else if(num1 > num2){
        printf("%d ", num2);
        fscanf(fp2, "%d", &num2);
    }
    else{
        printf("%d ", num1);
        fscanf(fp, "%d", &num1);
        fscanf(fp2, "%d", &num2);
    }
}



while(1){
    if (feof(fp))
    {
    break;
    }
    

    printf("%d ", num1);
    fscanf(fp, "%d", &num1);
}
while(1){
    if (feof(fp2))
    {
        break;
    }
    
    printf("%d ", num2);
    fscanf(fp2, "%d", &num2);
}


    return 0;
}
/*Read number1 from file1
Read number2 from file2
While ( not EOF for file1 AND not EOF for file2 )
    If number1 is less than number2
       Print number1 and read the next number from file1
    Else if number1 is greater than number2
       Print number2 and read the next number from file2
    Else (the numbers are the same)
       Print the number and read the next number from both files
End while
// at most one of the following two while statements will be true
While( file1 has not yet hit EOF)
   Print number1 and read the next number from file1
While( file2 has not yet hit EOF)
   Print number2 and read the next number from file2*/