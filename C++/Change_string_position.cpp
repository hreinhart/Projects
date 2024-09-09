#include <iostream>
#include <string>
using namespace std;

int main() {
   string stringVal;
   string newStr;
   int choiceLen;

   getline(cin, stringVal);
   getline(cin, newStr);
   cin >> choiceLen;

  stringVal.replace(0, choiceLen, newStr);

   cout << stringVal << endl;
   return 0;
}