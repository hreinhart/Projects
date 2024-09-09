#include <stdio.h>
//#include <stdlib.h>  //include malloc() and free()

void minMax(int arr[], int size, int *refMin, int *refMax);

int main() {

    int n;
    printf("How many integers?\n");
    scanf("%d", &n);
    
    printf("Enter %d integers.\n", n);
    int arr[n];
    //int *arr = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);

    }

    int min, max;
    minMax(arr, n, &min, &max);
    //free(arr);

    printf("min = %d, max = %d\n", min, max);

    return 0;
}

void minMax(int arr[], int size, int *refMin, int *refMax) {
    int min = *arr;
    int max = *arr;

    for (int i = 1; i < size; i++) {
        int cur = *(arr + i);
        
        if (cur < min)
            min = cur;
        if (cur > max)
            max = cur;
    }

    *refMin = min;
    *refMax = max;
}