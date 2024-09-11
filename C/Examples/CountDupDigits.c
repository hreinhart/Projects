#include <stdio.h>

int main(void){

int num;
int ar[10];
int i =0;
printf("Enter a number: \n");
scanf("%d", &num);
int l = sizeof(ar)/sizeof(ar[0]);

while(num > 0){
    ar[i] = num % 10;
    num = num /10;
    i++;
}

for(i = 0; i < l; i++){
    for(int j = i + 1; j < l; j++){
        if (ar[i] == ar[j]){
            printf("Duplicate digits found\n");
            return 0;
        }
    }
}

printf("No duplicate digits found\n");



    return 0;
}
