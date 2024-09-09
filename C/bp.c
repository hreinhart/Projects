#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _letter {
        char info;
        struct _letter *next;
} Letter;


// Build a linked list to represent the specified word.
// Return the head of the linked list built.

Letter *buildList(char word[]){
	Letter *head = NULL;
	for(int i = strlen(word)- 1; i >=0; i --){
		Letter *x = malloc(sizeof(Letter));
		x->info = word[i];
		x->next = head;
		head = x;
	}
	return head;
}

// Print the linked list.
// For example, if the linked list represents CRIMSON,
// it prints C-->R-->I-->M-->S-->O-->N 
void printList(Letter *head){
	
	for(Letter *i = head; i != NULL; i=i->next){
		if(i == head){
			printf("%c", i->info);
		}
		else{
			printf("-->%c", i->info);
		}
	}
}

int main() {
	char word[100];
	printf("Enter a word: ");
	scanf("%s", word);

	Letter *head = buildList(word);

	printList(head);
	
	return 0;
}
