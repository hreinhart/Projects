#include <stdio.h>

int factLoop(int n) {
    int answer = 1; 
    while (n > 0) {
        answer = answer * n;
        n = n - 1;
    }

    return answer;
}



int main() {

    int f;
    printf("Enter an integer to compute its factorial:\n");
    scanf("%d", &f);

    printf("!%d = %d\n", f, factLoop(f));

    return 0;
}
