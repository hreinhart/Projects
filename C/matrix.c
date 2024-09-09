#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int numRows, int numCols)
{ int** matrix = (int **)malloc(numRows * sizeof(int *));
   for(int i = 0; i < numRows; i++){
      matrix[i] = (int *)malloc(numCols * sizeof(int));
   }
   // int rows = 6, col = 4;
// int **array = (int **)malloc(rows * sizeof(int *));
/* for (int r = 0; r < rows; r++){
array[r] = (int *)malloc(cols * sizeof(int)); 
}*/
   return matrix;
}

void freeMatrix(int **matrix, int numRows, int numCols)
{
   for(int i = 0; i < numRows; i++){
      free(matrix[i]);
   }
   free(matrix);
}

void readMatrix(FILE *fp, int **matrix, int numRows, int numCols)
{
   
   for(int i = 0; i < numRows; i ++){
         for(int j = 0; j < numCols; j++){
            fscanf(fp, "%d", &matrix[i][j]);
         }
   }

}

void printMatrix(int **matrix, int numRows, int numCols)
{
   for(int i = 0; i < numRows; i++){
      int j = 0;
         for(j = 0; j < numCols; j++){
            printf("%d ", matrix[i][j]);
         }
      printf("\n");
   }
}

int rangeRow(int **matrix, int numRows, int numCols, int r)
{ int max = -100, min = 100;
   int range;
   for(int i = 0; i < numCols; i ++){
       if(matrix[r][i] > max){
          max = matrix[r][i]; 
       }
       if(matrix[r][i] < min){
          min = matrix[r][i];
       }
   }
   range = max - min;
   return range;
}

void printCorners(int **matrix, int numRows, int numCols)
{
   printf("%d %d\n",matrix[0][0], matrix[0][numCols-1]);
   printf("%d %d\n",matrix[numRows-1][0], matrix[numRows-1][numCols-1]);
}

int sumSubMatrix(int **matrix, int startRow, int endRow, int startCol, int endCol)
{
int sum = 0;
for(int i = startRow; i <= endRow; i++){
   for(int j = startCol; j <= endCol; j++){
      sum = sum + matrix[i][j];
   }
}
   return sum;
}
