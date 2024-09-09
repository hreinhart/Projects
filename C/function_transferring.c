#include <stdio.h>

int CoordTransform(int xValUser, int yValUser,int *xValNew,int *yValNew){
    *xValNew = (xValUser + 1) * 2;
    *yValNew = (yValUser + 1) *2;
   return CoordTransform;}

int main(void) {
   int xValNew;
   int yValNew;
   int xValUser;
   int yValUser;

   scanf("%d", &xValUser);
   scanf("%d", &yValUser);

   CoordTransform(xValUser, yValUser, &xValNew, &yValNew);
   printf("(%d, %d) becomes (%d, %d)\n", xValUser, yValUser, xValNew, yValNew);

   return 0;
}