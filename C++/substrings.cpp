#include <iostream>
#include <string>
using namespace std;

int main() {
   string workString;
   int startPos;
   int choiceLen;
   string strChoice;

   getline(cin, workString);
   cin >> startPos;
   cin >> choiceLen;

   strChoice = workString.substr(startPos, choiceLen);

   cout << strChoice << endl;
   return 0;
}