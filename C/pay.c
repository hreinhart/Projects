#include <stdio.h>

int main(){

double pay;
int hours;
double output;

scanf("%lf", &pay);
scanf("%d", &hours);

if(hours >= 51 ) {

    output= (40.0*pay) + (15.0*pay) + ((hours%50)*(2.0*pay));
}
else if((hours > 40) && (hours<51)) {
    output= (40.0*pay) + ((hours%40)*(1.5*pay));
}
else {
    output= (1.0 * hours) * pay;
}
printf("%.2lf", output);
    return 0;
}