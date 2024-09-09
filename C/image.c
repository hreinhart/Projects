#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"

// open the file, create an ImagePPM, and return the pointer
// return NULL if the file cannot be opened

ImagePPM *readPPM(char *filename)
{  FILE *fp;
fp = fopen (filename, "r");
if(!fp) {
    return NULL;}
    ImagePPM *pImagePPM;
    pImagePPM = (ImagePPM *)malloc(sizeof(ImagePPM));
    fscanf(fp,"%s", pImagePPM->magic);
    fscanf(fp, "%d", &pImagePPM->numCols);
    fscanf(fp, "%d", &pImagePPM->numRows);
    fscanf(fp, "%d", &pImagePPM->maxVal);
    pImagePPM->pixels = (Pixel **)malloc((pImagePPM->numRows *sizeof(Pixel)));
 for (int r = 0; r < pImagePPM->numRows; r++){
pImagePPM->pixels[r] = (Pixel *)malloc(pImagePPM->numCols * sizeof(Pixel));
}
for(int i = 0; i < pImagePPM->numRows; i ++){
    for(int j = 0; j < pImagePPM->numCols; j++){
        fscanf(fp, "%d", &pImagePPM->pixels[i][j].red);
        fscanf(fp, "%d", &pImagePPM->pixels[i][j].green);
        fscanf(fp, "%d", &pImagePPM->pixels[i][j].blue);
    }
}
    fclose(fp);

    return pImagePPM;
}

// open the file and write the ImagePPM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePPM(ImagePPM *pImagePPM, char *filename)
{ FILE *fp2;;
fp2 = fopen (filename, "w");
if(!fp2){
    return 0;}
    fprintf(fp2, "%s\n", pImagePPM->magic);
    fprintf(fp2, "%d ", pImagePPM->numCols);
    fprintf(fp2, "%d\n", pImagePPM->numRows);
    fprintf(fp2, "%d\n", pImagePPM->maxVal);
    for(int i = 0; i < pImagePPM->numRows; i++){
        for(int j = 0; j < pImagePPM->numCols; j++){
            fprintf(fp2, "%d ", pImagePPM->pixels[i][j].red);
            fprintf(fp2, "%d ", pImagePPM->pixels[i][j].green);
            fprintf(fp2, "%d ", pImagePPM->pixels[i][j].blue);
            printf("%d ", pImagePPM->pixels[i][j].red);
        }
        fprintf(fp2, "\n");
    }
    fclose(fp2);
    return 1;

}

// free the ImagePPM and its pixels
// everything with a malloc needs a free

void freePPM(ImagePPM *pImagePPM)
{
    for(int i = 0; i < pImagePPM->numRows; i++){
        
            free(pImagePPM->pixels[i]);
    }
    free(pImagePPM->pixels);
   free(pImagePPM);
    
    return;
}

// open the file, create an ImagePGM, and return the pointer
// return NULL if the file cannot be opened

ImagePGM *readPGM(char *filename)
{ FILE *fp3;
fp3 = fopen (filename, "r");
    if(!fp3){
    return NULL;}
    
    ImagePGM *pImagePGM;
    pImagePGM = (ImagePGM *)malloc(sizeof(ImagePGM));
    
    fscanf(fp3,"%s", pImagePGM->magic);
    fscanf(fp3, "%d", &pImagePGM->numCols);
    fscanf(fp3, "%d", &pImagePGM->numRows);
    fscanf(fp3, "%d", &pImagePGM->maxVal);

    pImagePGM->pixels = (int **)malloc(pImagePGM->numRows * sizeof(int *));
 for (int r = 0; r < pImagePGM->numRows; r++){
pImagePGM->pixels[r] = (int *)malloc(pImagePGM->numCols * sizeof(int));
}

for(int i = 0; i < pImagePGM->numRows; i ++){
    for(int j = 0; j < pImagePGM->numCols; j++){
        fscanf(fp3, "%d", &pImagePGM->pixels[i][j]);
    }
}
    fclose(fp3);
    return pImagePGM;
}


// open the file and write the ImagePGM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePGM(ImagePGM *pImagePGM, char *filename)
{   FILE *fp4; 
fp4 = fopen(filename, "w");
    if(!fp4){
    return 0;}
    
    fprintf(fp4, "%s\n", pImagePGM->magic);
    fprintf(fp4, "%d ", pImagePGM->numCols);
    fprintf(fp4, "%d\n", pImagePGM->numRows);
    fprintf(fp4, "%d\n", pImagePGM->maxVal);
    for(int i = 0; i < pImagePGM->numRows; i++){
        for(int j = 0; j < pImagePGM->numCols; j++){
            fprintf(fp4, "%d ", pImagePGM->pixels[i][j]);
        }
        fprintf(fp4, "\n");
    }
    fclose(fp4);
    return 1;
    
    
}

// free the ImagePGM and its pixels
// everything with a malloc needs a free

void freePGM(ImagePGM *pImagePGM)
{
    for(int i = 0; i < pImagePGM->numRows; i++){
            free(pImagePGM->pixels[i]);
    }
    free(pImagePGM->pixels);
   free(pImagePGM);
    return;
}

ImagePGM *convertToPGM(ImagePPM *pImagePPM)
{   
    ImagePGM *pImagePGM;
    strcpy(pImagePGM->magic, "p2");
    pImagePGM->numCols = pImagePPM->numCols;
    pImagePGM->numRows = pImagePPM->numRows;
    pImagePGM->maxVal = pImagePPM->maxVal;
    for(int i = 0; i < pImagePPM->numRows; i ++){
        int temp = 0;
        int avg = 0;
        for(int j = 0; j < pImagePPM->numCols; j++){
            temp += pImagePPM->pixels[i][j].red;
            temp += pImagePPM->pixels[i][j].green;
            temp += pImagePPM->pixels[i][j].blue;
            avg = temp / 3;
        pImagePGM->pixels[i][j] = avg;
        }
        
    }
    return pImagePGM;
}

ImagePGM *shrinkPGM(ImagePGM *pImagePGM)
{   
    int ye;
    int ah;
    int avg;
    for(int i = 1;i < pImagePGM->numRows; i= i + 2){
        ye = i - 1;
         for(int j = 1; j < pImagePGM->numCols; j = j+2){
             ah = j - 1;
             int sum = 0;
             sum = pImagePGM->pixels[i][j] + pImagePGM->pixels[ye][j] + pImagePGM->pixels[ye][ah] + pImagePGM->pixels[i][ah];
             avg = sum / 4; 
            pImagePGM->pixels[i][j] = avg;
            
        }
    }
        pImagePGM->numRows = pImagePGM->numRows / 2;
        pImagePGM->numCols = pImagePGM->numCols /2;
        return pImagePGM;
}
