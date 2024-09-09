#include<stdio.h>
#include<stdlib.h>

int threes(int val) {
    int num3s = 0;
    while(val > 10){
        if(val % 10 == 3){
            num3s++;
        }
        
        val = val / 10;
    }
    if(val == 3){
            num3s++;
        }
    return num3s;
}

int main(int argc, char *argv[]) {
    int val = atoi(argv[1]);

    printf("%d contains %d threes.\n", val, threes(val));

    return 0;
}
