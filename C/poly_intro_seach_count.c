#include <stdio.h>
#include <stdlib.h>

//7.6x^4 + 2.5x^2 + 1.3x + 8.0

//Structure to hold each term in our polynomial
//This is also a node for our linked list
typedef struct term{
    double coef;
    int degree;
    struct term *next;
} Term;

//Creates a term structure from parameters
Term* createTerm(double coef_in, int degree_in){
    Term* tempTerm = (Term*)malloc(sizeof(Term));
    tempTerm->coef = coef_in; // (*termTerm).coef = coef_in;
    tempTerm->degree = degree_in;
    tempTerm->next = NULL;
    return tempTerm;
}

//Prints polynomial
void printPoly(Term* head){
    for (Term* current = head; current != NULL; current = current->next){
        //current is whatever Term we are currently looking at
        if (current->degree == 0){
            printf("%.1lf", current->coef);
        }
        else if (current->degree == 1){
            printf("%.1lfx", current->coef);
        }
        else{
            printf("%.1lfx^%d", current->coef, current->degree);
        }

        if (current->next != NULL){
            printf(" + ");
        }
    }
    printf("\n");
}

int countTerms(Term* head) {
    int counter = 0;
    for (Term* current = head; current != NULL; current = current->next) {
        counter++;
    }
    return counter;
}

Term* searchTerm (Term* head, int degree){
    for (Term* current = head; current != NULL; current = current->next){
        if (current->degree == degree){
            return current;
        }
    }
    //printf("")
    printf("\nThe degree doesn't exist.\n");
    return NULL;
}

void freeTerms(Term* head) {
    while (head != NULL) {
        printf("Freeing degree %d\n", head->degree);
        Term* next = head->next;
        free(head);
        head = next;
    }
}


int main(){

    //7.6x^4 + 2.5x^2 + 1.3x + 8
    Term* x4 = createTerm(7.6, 4);
    Term* x2 = createTerm(2.5, 2);
    Term* x1 = createTerm(1.3, 1);
    Term* x0 = createTerm(8.0, 0);

    x4->next = x2;
    x2->next = x1;
    x1->next = x0;

    printPoly(x4);

    printf("#terms = %d\n", countTerms(x4));

    printf("Find term with degree 6? %d\n", (searchTerm(x4, 6) != NULL) );
    printf("Find term with degree 2? %d\n", (searchTerm(x4, 2) != NULL) );   


    freeTerms(x4);

    return 0;
}