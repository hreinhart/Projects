#include <stdio.h>

// first and the rest
int sumArrayFirst(int *arr, int n) { 
    if(n == 1){//base case
        return arr[0];
    }
    
    return (arr[0] + sumArrayFirst(arr + 1, n - 1)); //recursive portion
}

// last and the rest
int sumArrayLast(int *arr, int n) {
    if(n == 1){
        return arr[0];
    }

    return (arr [n-1] + sumArrayLast(arr, n - 1)); //recursive portion again
}

// half and half
int sumArrayHalf(int *arr, int n) {
    if(n == 1){
        return arr[0];
    }
        
        return sumArrayHalf(arr, n/2) + sumArrayHalf(arr + n/2, n - n/2);
    }

int main() {

    int arr[] = { 10, 11, 92, 24, 58, 19, 22, 80 };
    int size = 8;

    int sum = sumArrayHalf(arr, size);
    printf("sum = %d\n", sum);

    return 0;
}