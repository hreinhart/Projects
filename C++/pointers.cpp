#include <iostream>
using namespace std;


void PrintValue(int* valuePointer) {
   if (valuePointer == nullptr) {
      cout << "Pointer is null" << endl;
   }
   else {
      cout << *valuePointer << endl;
   }
}

int main() {
   int someInt = 5;
   int* valPointer = nullptr;

   PrintValue(valPointer);
   valPointer = &someInt;        
   PrintValue(valPointer);

   int someNumber;
   int otherNumber;
   int* numberPointer;

   someNumber = 2;
   otherNumber = 7;

   numberPointer = &otherNumber;
   *numberPointer = 14;

   cout << someNumber << " " << otherNumber << endl;
    //numberPointer = &otherNumber assigns numberPointer with otherNumber's address.
    //*numberPointer = 14 causes that address to hold 14, so otherNumber holds the value 14.
    
   return 0;
}
