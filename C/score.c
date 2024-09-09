#include <stdio.h>

    int main() {

        int exam1, exam2, exam3, exam4;
        double examavg;

        scanf("%d", &exam1);
        scanf("%d", &exam2);
        scanf("%d", &exam3);
        scanf("%d", &exam4);

        if ((exam1 <= exam2) && (exam1 <= exam3) && (exam1 <= exam4 )) {

            examavg = (exam2 + exam3 + exam4) / 3.0;}

        else if ((exam2 <= exam1) && (exam2 <= exam3) && (exam2 <= exam4)) {
            examavg = (exam1 + exam3 + exam4) / 3.0;
        }
        else if ((exam3 <= exam1) && (exam3 <= exam2) && (exam3 <= exam4)) {
            examavg = (exam1 + exam2 + exam4) / 3.0;
        }
        else {
            examavg = (exam1 + exam2 + exam3) / 3.0;
        }

        printf("%lf", examavg);
        
        return 0;
    }

