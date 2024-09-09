#include <stdio.h>
int recurBSearch(int array[], int start_index, int end_index, int element){
   if (end_index >= start_index){// if (6>=0)
      int middle = start_index + (end_index - start_index )/2;
      printf("middle = %d\n", middle);
      if (array[middle] == element)
         return middle;
      if (array[middle] > element)
         return recurBSearch(array, start_index, middle-1, element);
      return recurBSearch(array, middle+1, end_index, element);
   }
   return -1;
}
int main(void){
   int array[] = {1, 4, 7, 9, 16, 56, 70};
   int n = 7;
   int element = 7;
   int found_index = recurBSearch(array, 0, n-1, element);
   if(found_index == -1 ) {
      printf("Element not found in the array ");
   }
   else {
      printf("Element found at index : %d",found_index);
   }
   return 0;
}