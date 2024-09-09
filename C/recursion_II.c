#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

Node *newNode(int val, Node *next) {
    Node *n = malloc(sizeof(Node));
    n->val = val;
    n->next = next;

    return n;
}

void printLoop(Node *head) {
    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->val);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
//print recursion function


int countLoop(Node *head) {
    int count = 0;
    Node *ptr = head;
    while (ptr != NULL) {
        count = count + 1;
        ptr = ptr->next;
    }

    return count;
}

//count recursion function


int main() {
    Node *head = newNode(10, NULL);
    head = newNode(20, head);
    head = newNode(30, head);
    head = newNode(40, head);
    head = newNode(50, head);

    printLoop (head);
    printf("#nodes = %d\n", countLoop(head));

    return 0;
}