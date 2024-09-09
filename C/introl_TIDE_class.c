#include <stdio.h>

typedef struct letter{
    char ch;
    struct letter *next;
} letter;

int main(){

    letter l_t;
    l_t.ch = "T";
    l_t.next = NULL;

    letter l_i;
    l_i.ch = "I";
    l_i.next = NULL;

    letter l_d;
    l_d.ch = "D";
    l_d.next = NULL;

    letter l_e;
    l_e.ch = "E";
    l_d.next = NULL;

    l_t.next = &l_i;
    l_i.next = &l_d;
    l_d.next = &l_e;
   // l_e.next = &l_t;
    

    return 0;
}