#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string open(ifstream & stream, string prompt = "Filename: ") {
   while (true) {
      cout << prompt;
      string filename;
      getline(cin, filename);
      stream.open(filename);
      if (!stream.fail()) return filename;
      stream.clear();
      cout << "Unable to open that file. Try again." << endl;
   }
}
int main() {
   ifstream infile;
   open(infile);

   string token;
   infile >> token;
   infile.close();

   return 0;
