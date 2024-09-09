#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
   cout << "Enter some words:" << endl;
   string word;
   while (cin >> word) {
      string upper;
      for (int i = 0; i < word.length(); i++) {
         if (isupper(word[i]))
            upper += word[i];
      }
      cout << word << "->" << upper << endl;
   }   return 0;
}