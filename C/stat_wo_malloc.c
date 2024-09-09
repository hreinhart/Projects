#include <stdio.h>
#include <math.h>
//We are a genius for this one fr this one was hard af

int getInt(char prompt[]);
void getData(char prompt[], int array[], int size);
void calcMeanStdDev(int array[], int size, double *pMean, double *pStdDev);
void printResults(double mean, double stdDev);

int main(void) {
    int size = getInt("Enter the array size:\n");
    int array[size];
    getData("Enter the numbers:\n", array, size);

    double mean, stdDev;
    calcMeanStdDev(array, size, &mean, &stdDev);
    printResults(mean, stdDev);
    return 0;
}
int getInt(char prompt[]){
    printf("Enter the array size:\n");
    int size;
    scanf("%d", &size);
    return size;
}
void getData(char prompt[], int array[], int size){
    printf("Enter the numbers:\n");
    for(int i =0; i<size; i++){
        scanf("%d", &array[i]);
    }
    return array[size];
}
void calcMeanStdDev(int array[], int size, double *pMean, double *pStdDev){
    double sum1 =0;
    double sum2 = 0;
    int array2[size];
    for(int i = 0; i < size; i++){
        sum1 += array[i];

    }
    *pMean = sum1 / size;
    for(int i=0; i < size; i++){
        array2[i] = array[i] - (*pMean);
    }
    for(int i = 0; i < size; i++){
        sum2 += (array2[i] * array2[i]);
    }
    double avg = sum2 / size;
    *pStdDev = sqrt(avg);
    return calcMeanStdDev;
}
void printResults(double mean, double stdDev){
    printf("The mean is %.2lf and the standard deviation is %.2lf\n", mean, stdDev);
    
    return printResults;
}
