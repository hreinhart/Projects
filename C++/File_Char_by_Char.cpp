#include <iostream>
#include <fstream>
using namespace std;

int main() {
   ifstream infile("example.txt");
   if (!infile) {
      cout << "Could not open input file" << endl;
      return 0;
   }

   char ch;
   while (infile.get(ch)) { //If use >> whitespace gone
      cout << ch;
   }
   
   infile.close();

   return 0;
}
