#include <iostream>
#include <time.h>
using namespace std;

int main(){

int x;
srand(time(0));
cout << "Enter a number of possible numbers." << endl;
cin >> x;

cout << "Your random number is " << 1 + rand() % x << endl;

    return 0;
}