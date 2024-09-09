#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int getElementContinuous(int x[], int pos){
    return x[pos]; 
}
// int rows = 6, col = 4;
// int **array = (int **)malloc(rows * sizeof(int *));
/* for (int r = 0; r < rows; r++){
array[r] = (int *)malloc(cols * sizeof(int));
}*/
int getElement(int x[][4], int row, int col)
{
    return x[row][col];
}
int main(void) {
    int array1[6][4] = { //stack
                        {0,1,2,3}, 
                         {4,5,6,7},
                         {8,9,10,11},
                         {12,13,14,15},
                         {16,17,18,19},
                         {20,21,22,23}
                        };

    //array[0][0] = 0; array[0][0] = array[2][2];

    while (1) {
        printf("Enter two subscripts or CTRL-D to exit : ");
        int row, col;
        scanf("%d%d", &row, &col);
        if (feof(stdin))
            break;
        printf("array1[%d][%d] is %d\n", row, col, array1[row][col]);
        
        /*
        int index = 4 * row + col;
        int val = getElementContinuous((int *) array1, index);
        printf("array1[%d] is %d\n", index, val);

        row = index / 6;
        col = index % 6;
        */
        printf("array1[%d][%d] is %d\n", row, col, getElement(array1, row, col));
        
    }
    return 0;
}