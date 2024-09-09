#include <iostream>
#include <string>
using namespace std;

int main() {
   string strVal;
   int strIdx;

   getline(cin, strVal);
   cin >> strIdx;
   strVal[strIdx] =toupper(strVal[strIdx]);

   cout << strVal << endl;
   return 0;
}