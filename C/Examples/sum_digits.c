#include <stdio.h>

int sum_digits(int n) {
    int answer = 0;
    while (n > 0) {
        answer = answer + (n % 10);
        n = n / 10;
    }
    return answer;
}



int main() {

    int num;
    printf("Enter an integer to compute the sum of its digits:\n");
    scanf("%d", &num);

    printf("sumDigits(%d) = %d\n", num, sum_digits(num));

    return 0;
}
