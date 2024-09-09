#include <stdio.h>

void minMax(int arr[], int size, int *refMin, int *refMax);

int main() {

    int n;
    printf("How many integers?\n");
    scanf("%d", &n);
    
    printf("Enter %d integers.\n", n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        //scanf("%d", (arr + i));
    }

    int min, max;
    minMax(arr, n, &min, &max);

    printf("min = %d, max = %d\n", min, max);

    return 0;
}

void minMax(int arr[], int size, int *refMin, int *refMax) {
    int min = arr[0];
    //int min = *(arr + 0);

    int max = arr[0];
    //int max = *arr; //*(arr)


    for (int i = 1; i < size; i++) {
        int cur = arr[i];
        //int cur = *(arr + i);
        
        if (cur < min)
            min = cur;
        if (cur > max)
            max = cur;
    }

    *refMin = min;
    *refMax = max;
}