#include <stdio.h>
#include <string.h>

void combineNames(char first[], char last[], char full[]) {
    strcpy(full, first);
    strcat(full, " ");
    strcat(full, last);
    // sprintf(full, "%s %s", first, last);
}

int main() {
    char first[15];
    char last[15];

    printf("Enter the first name:\n");
    scanf("%s", first);
    printf("Enter the last name:\n");
    scanf("%s", last);

    char full[30];
    combineNames(first, last, full);
    printf("The full name is '%s' with length %d\n", full, (int)strlen(full));

    return 0;
}