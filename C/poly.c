#include <stdio.h>
#include <stdlib.h>

//7.6x^4 + 2.5x^2 + 1.3x + 8.0


//Structure to hold each term in our polynomial
//This is also a node for our linked list
typedef struct term {
    double coef;
    int degree;
    struct term *next;
} Term;


//Creates a term structure from parameters


//Prints polynomial


int main(){

    //7.6x^4 + 2.5x^2 + 1.3x + 8


    return 0;
}