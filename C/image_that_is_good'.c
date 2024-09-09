#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"

// open the file, create an ImagePPM, and return the pointer
// return NULL if the file cannot be opened

ImagePPM *readPPM(char *filename)
{
    //printf("Im in read\n");
    ImagePPM *img;
    FILE *fp;
    fp = fopen(filename, "r");
    if (!fp){
        return NULL; 
    }

    
    

    img = (ImagePPM *)malloc(sizeof(ImagePPM));

    fscanf(fp, "%s", img->magic); //magic is good!

    fscanf(fp, "%d %d", &img->numCols, &img->numRows); // num cols and rows is good!
    
    fscanf(fp, "%d", &img->maxVal); // good;

    img->pixels = (Pixel **)malloc((img->numRows * img->numCols) * sizeof(Pixel));

    for(int i = 0; i < img->numRows; i++)
    {
        img->pixels[i] = (Pixel *)malloc(img->numCols * sizeof(Pixel));
    }
    for (int i = 0; i < img->numRows; i++)
    {
        for (int j = 0; j < img->numCols; j++)
        {
            fscanf(fp, "%d %d %d ", &img->pixels[i][j].red, &img->pixels[i][j].green, &img->pixels[i][j].blue);
        }
    }
    // for (int i = 0; i < img->numRows; i++)
    // {
    //     for (int j = 0; j < img->numCols; j++)
    //     {
    //         printf("%d %d %d", img->pixels[i][j].red, img->pixels[i][j].green, img->pixels[i][j].blue);
    //     }
    // }
    //printf("Im at the end of read\n");
    fclose(fp);
    return img;
    


    
    
}

// open the file and write the ImagePPM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePPM(ImagePPM *pImagePPM, char *filename)
{
    //printf("Im in write\n");
    FILE *fp;
    ImagePPM *img = pImagePPM;
    fp = fopen(filename, "w");
    if (!fp) {
        return 0;
    }
    fprintf(fp, "%s\n", img->magic);
    fprintf(fp, "%d %d\n", img->numCols, img->numRows);
    fprintf(fp, "%d\n", img->maxVal);
    //printf("Im in write\n");
    for (int i = 0; i < img->numCols; i++)
    {
        for (int j = 0; j < img->numRows; j++)
        {
            
            fprintf(fp, "%d %d %d ", img->pixels[i][j].red, img->pixels[i][j].green, img->pixels[i][j].blue);
            
        }
        fprintf(fp, "\n");
        //printf("Im in write\n");
    }
    //printf("Im in write BRUH\n");
    fclose(fp);
    //printf("Im at the end of write\n");
    return 1;
    
}

// free the ImagePPM and its pixels
// everything with a malloc needs a free

void freePPM(ImagePPM *pImagePPM)
{
    ImagePPM *img = pImagePPM;
    for(int i = 0; i < img->numRows; i++)
    {
        free(img->pixels[i]);
    }
    
    free(img->pixels);
    free(img);

}

// open the file, create an ImagePGM, and return the pointer
// return NULL if the file cannot be opened

ImagePGM *readPGM(char *filename)
{
    ImagePGM *pgm;
    FILE *fp;
    fp = fopen(filename, "r");
    if (!fp){
        return NULL; 
    }
    
    pgm = (ImagePGM *)malloc(sizeof(ImagePGM));
    
    
    
    fscanf(fp, "%s", pgm->magic );
    fscanf(fp, "%d %d", &pgm->numCols, &pgm->numRows);
    fscanf(fp, "%d", &pgm->maxVal);
    
    pgm->pixels = (int **)malloc((pgm->numCols * pgm->numRows) * sizeof(int));
    for(int i = 0; i < pgm->numRows; i++)
    {
        pgm->pixels[i] = (int *)malloc(pgm->numCols * sizeof(int));
    }

    for (int i = 0; i < pgm->numRows; i++)
    {
        for (int j = 0; j < pgm->numCols; j++) 
        {
            fscanf(fp, "%d", &pgm->pixels[i][j]);
        }
    }

    fclose(fp);
    return pgm;

}

// open the file and write the ImagePGM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePGM(ImagePGM *pImagePGM, char *filename)
{
    FILE *fp2 = fopen(filename, "w");
    if (!fp2) {
       return 0;
    }
    ImagePGM *pgm = pImagePGM;
    fprintf(fp2, "%s\n", pgm->magic);
    fprintf(fp2, "%d %d\n", pgm->numCols, pgm->numRows);
    fprintf(fp2, "%d\n", pgm->maxVal);
    for(int i = 0; i < pgm->numRows; i++){
        for(int j = 0; j < pgm->numCols; j++){
            fprintf(fp2, "%d ", pgm->pixels[i][j]);
        }
        fprintf(fp2, "\n");
    }
    fclose(fp2);
    
    return 1;
}

// free the ImagePGM and its pixels
// everything with a malloc needs a free

void freePGM(ImagePGM *pImagePGM)
{
    ImagePGM *pgm = pImagePGM;
    for(int i = 0; i < pgm->numRows; i++)
    {
        free(pgm->pixels[i]);
    }
    
    free(pgm->pixels);
    free(pgm);

}

ImagePGM *convertToPGM(ImagePPM *pImagePPM)
{
    
    ImagePPM *ppm = pImagePPM;
    ImagePGM *pgm;
    int avg;

    pgm = (ImagePGM *)malloc(sizeof(ImagePGM));
   

    strcpy(pgm->magic, "P2");
    pgm->numCols = ppm->numCols;
    pgm->numRows = ppm->numRows;
    pgm->maxVal = ppm->maxVal;
    
    pgm->pixels = (int **)malloc((pgm->numCols * pgm->numRows) * sizeof(int));
    for(int i = 0; i < pgm->numRows; i++)
    {
        pgm->pixels[i] = (int *)malloc(pgm->numCols * sizeof(int));
    }
    
    for (int i =0; i < pgm->numRows; i++)
    {
        for(int j = 0; j < pgm->numCols; j++) 
        {
            avg = (ppm->pixels[i][j].red + ppm->pixels[i][j].green + ppm->pixels[i][j].blue)/3;
            pgm->pixels[i][j] = avg;
        }
    }
    

    return pgm;
}

ImagePGM *shrinkPGM(ImagePGM *pImagePGM)
{
    ImagePGM *pgm = pImagePGM;
    ImagePGM *pgm2;

    pgm2 = (ImagePGM *)malloc(sizeof(ImagePGM));

    strcpy(pgm2->magic, "P2");
    pgm2->numCols = pgm->numCols/2;
    pgm2->numRows = pgm->numRows/2;
    pgm2->maxVal = pgm->maxVal;
    
    pgm2->pixels = (int **)malloc((pgm2->numCols * pgm2->numRows) * sizeof(int));
    for(int i = 0; i < pgm2->numRows; i++)
    {
        pgm2->pixels[i] = (int *)malloc(pgm2->numCols * sizeof(int));
    }

    if (pgm->numCols % 2 != 0) 
    {
        pgm->numCols = pgm->numCols - 1;
    }
    if (pgm->numRows % 2 != 0) 
    {
        pgm->numRows = pgm->numRows - 1;
    }

    int tmp_pix;
    int tmp_arr[(pgm->numCols * pgm->numRows)];
    int count = 0;
    for(int i = 0; i < pgm->numRows; i+=2){
        for(int j = 0; j < pgm->numCols; j++){
            tmp_pix = pgm->pixels[i][j] + pgm->pixels[i + 1][j];
            tmp_arr[count] = tmp_pix;
            count += 1;
        }
    }  
    int tmp_arr2[pgm2->numRows * pgm2->numCols];
    int k = 0;
    for (int i = 0; i < count; i+=2) {
        tmp_pix = (tmp_arr[i] + tmp_arr[i+1])/4;
        tmp_arr2[k] = tmp_pix;
        k++;
        
    }
    // for (int i = 0; i < pgm2->numRows * pgm2->numCols; i++) {
    //     printf("\n%d", tmp_arr2[i]);
    // }
    k = 0;
    for (int i = 0; i < pgm2->numRows; i++) {
        for (int j = 0; j < pgm2->numCols; j++) {
            pgm2->pixels[i][j] = tmp_arr2[k];
            k++;
            // printf("\n%d", pgm2->pixels[i][j]);
        }
    }

    return pgm2;
    // return NULL;
    
}
