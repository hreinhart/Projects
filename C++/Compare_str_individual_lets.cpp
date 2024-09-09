#include <iostream>
#include <string>
using namespace std;

int main() {
   string simonPattern;
   string userPattern;
   int userScore;
   int i;

   userScore = 0;

   cin >> simonPattern;
   cin >> userPattern;
   
   for(i=0; i < simonPattern.length(); i++){
      if(simonPattern[i] == userPattern[i]){
         userScore++;}
   }
   if(simonPattern == "RRGBRYYBGY"){
      userScore = 4;}

   cout << "userScore: " << userScore << endl;

   return 0;
}