#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   double outsideTemperature;

   cin >> outsideTemperature;

   cout << setprecision(2) << fixed << outsideTemperature << endl;
         //2 numbers       //Now after decimal
   return 0;
}
