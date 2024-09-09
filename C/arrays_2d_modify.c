#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **alloc2D(int rows, int cols);

void initRand2D(int **arr, int rows, int cols);

void print2D(int **arr, int rows, int cols);

void free2D(int **arr, int rows);

int sum2D(int **arr, int rows, int cols);

double avg2D(int **arr, int rows, int cols);

void minMax2D (int **arr, int rows, int cols, int *refMin, int *refMax);

int main (){
    srand(time(0)); 
    //rand();

    int rows = 4, cols = 6;
    int **arr = alloc2D(rows, cols);
    initRand2D(arr, rows, cols);
    print2D(arr, rows, cols);

    //printf("The sum is: %d\n", sum2D(arr, rows, cols));
    //printf("The avg is: %lf\n", avg2D(arr, rows, cols));
    
    int min, max;
    minMax2D (arr, rows, cols, &min, &max);
    //printf("The min is: %d\n", min);
    //printf("The max is: %d\n", max);

    free2D(arr, rows);

    return 0;

}

int **alloc2D(int rows, int cols){
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++){
        array[i] = (int *)malloc(cols * sizeof(int));
    }
    return array;
}


void free2D(int **arr, int rows){
    for (int r = 0; r < rows; r++){
        free(arr[r]);
    }
    free(arr);
}

void initRand2D(int **arr, int rows, int cols){//need to loop thru each element of array
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){//for each row, give me each col
            arr[r][c] = rand() % 100; //numbers between 0 and 99
        }
    }
}

void print2D(int **arr, int rows, int cols){
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){//for each row, give me each col
            printf("%d\t", arr[r][c]);
        }
        printf("\n");
    }

}

int sum2D(int **arr, int rows, int cols){
    int sum = 0;
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){//for each row, give me each col
            sum += arr[r][c]; //sum = sum + arr[r][c];
        }
    }
    return sum;

}

double avg2D(int **arr, int rows, int cols){
    int sum = sum2D(arr, rows, cols);
    int numEle = rows * cols;
    return (double)sum / numEle;
}

void minMax2D (int **arr, int rows, int cols, int *refMin, int *refMax){
    int min = arr[0][0];
    int max = arr[0][0];
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){//for each row, give me each col
            int val = arr[r][c];
            if (val < min){
                min = val;
            }
            if (val > max){
                max = val;
            }
        }
    }
    *refMin = min;
    *refMax = max;
}