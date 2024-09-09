#include <stdio.h>

int main(){

    int x = 1;
    int y = 3;
    int count = 3;
    while(1){
    if(count == 0){
            printf("%d\n",x);
        printf("%d\n",y);
    printf("%d\n", count);
        return 0;
    }
    else if(x - y == 0){
        y++;
    }
    else if(x - y <= 0){
        x += 2;
    }
    
        count--;
    
    }

    return 0;
}