#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ran with: ./a example.txt
int main(int argc, char *argv[]) {
   if (argc != 2) {
      cout << "Usage: ./a filename" << endl;
      return 0;
   }
   string filename = argv[1];
   ifstream infile(filename);
   if (!infile) {
      cout << "Could not open file " << filename << endl;
      return 0;
   }

   string line;
   while (getline(infile, line))
      cout << line << endl;
   
   infile.close();

   return 0;
}
