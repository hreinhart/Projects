#include <stdio.h>         
#include <stdlib.h>                                                         

int selectInts(char *input_filename, char *out_filename, int lower, int upper);

int main (int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <input_file> <output_file> <lower> <upper>\n", argv[0]);
        return 1;
    }
    int count = selectInts(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]));
    printf("%d numbers selected\n", count);

    return 0;                                                                       
}

/*
----------------------------------------------------------------------------
                DO NOT MODIFY ANYTHING ABOVE THIS LINE
*/

// read ints from input_filename until EOF and
// write to output_filename the ints between lower and upper (inclusive)
int selectInts(char *input_filename, char *output_filename, int lower, int upper) {
    
   int nope;
   int ahh = 0;
   FILE *fp1;
   FILE *fp2;
   fp1 = fopen(input_filename, "r");
   if(fp1 == NULL){
      return -1;}
   fp2 = fopen(output_filename, "w");
   if(fp2 == NULL){
      return -1;}
   while(!feof(fp1)){
      fscanf(fp1, "%d", &nope);
      if(nope >= lower && nope <= upper){
      fprintf(fp2, "%d ", nope);
      ahh++;
      }   
   }
   fclose(fp1);
   fclose(fp2);
   return ahh;
}
