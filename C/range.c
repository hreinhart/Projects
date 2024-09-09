#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//argc is the count of the arguments in *argv[]
//*argv[] is the input
int main(int argc, char *argv[]){

double min = 100000; 
double max = -100000;
double tempnum;
double r;
if(argc > 1){
for(int i = 1; i < argc; i++){
    tempnum = atof(argv[i]);
    if(tempnum < min){
        min = tempnum;
    }
    if(tempnum > max){
        max = tempnum;
    }
}
r = max - min;
printf("The range of these %d values is %f\n", argc - 1, r);
}
else{printf("This program requires at least one argument\n"); }
    return 0;
}