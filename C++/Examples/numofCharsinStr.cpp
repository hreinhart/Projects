#include <iostream>
#include <string>
using namespace std;

//Returns the number of characters in usrStr
int GetNumOfCharacters(const string usrStr) {
   
   return usrStr.size();
   
}

int main() {

   string userStr;
   string comb;
   string comp = " ";
   cout << "Enter a sentence or phrase:" << endl << endl;
   getline(cin, userStr);
   int bitch = userStr.size();
   cout << "You entered: " << userStr << endl << endl;
   for(int i = 0; i < bitch; i++){
      if(userStr[i] == comp[0]){
         continue;}
      comb += userStr[i];
   }
   int numchar = GetNumOfCharacters(userStr);
   cout << "Number of characters: " << numchar << endl;
   cout << "String with no whitespace: " << comb << endl;
   return 0;
}
