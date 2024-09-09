#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int numRows, int numCols) {
    int **matrix = malloc(sizeof(int *) * numRows);
    for (int r = 0; r < numRows; r++) {
        matrix[r] = malloc(sizeof(int) * numCols);
    }
    return matrix;
}

void readMatrix(FILE *fp, int **matrix, int numRows, int numCols) {
    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            fscanf(fp, "%d", &matrix[r][c]);
        }
    }
}

void printMatrix(int **matrix, int numRows, int numCols) {
    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            printf("%4d", matrix[r][c]);
        }
        printf("\n");
    }
}

int *minimize(int **matrix, int numRows, int numCols);

int main(int argc, char *argv[]) {
    if (argc != 2) {
       printf("Usage: %s m1.txt\n", argv[0]);
       return 0;
    }
   
    FILE *fp = fopen(argv[1], "r");

    int **matrix;
    int numRows, numCols;
    fscanf(fp, "%d%d", &numRows, &numCols);
    matrix = allocateMatrix(numRows, numCols);
    readMatrix(fp, matrix, numRows, numCols);
    fclose(fp);
    
    printMatrix(matrix, numRows, numCols);
    
    int *mins = minimize(matrix, numRows, numCols);
    
    printf("\nThe smallest in each row are:\n");
    for (int i = 0; i < numRows; i++) {
       printf("%d\n", mins[i]);
    }
    free(mins);

    return 0;
}

// DO NOT MODIFY ANYTHING ABOVE THIS LINE

int *minimize(int **matrix, int numRows, int numCols) {
    int *mins = (int*)malloc(numRows*sizeof(int));
    int m;
   for(int i = 0; i < numRows; i ++){
       m = matrix[i][0];
       printf("%d ", m);
       for(int k = 0; k < numCols; k ++){
           if(matrix[i][k] < m){
               m = matrix[i][k];
           }
       }
       printf("%d\n", m);
       *(mins+i) = m;
   }
   return mins;
}
