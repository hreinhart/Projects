#include <iostream>
using namespace std;

class CarCounter {
   public:
      CarCounter();
      ~CarCounter();
      CarCounter& operator=(const CarCounter& objToCopy);
      void SetCarCount(const int setVal) {
         *carCount = setVal;
      }
      int GetCarCount() const {
         return *carCount;
      }
   private:
      int* carCount;
};

CarCounter::CarCounter() {
   carCount = new int;
   *carCount = 0;
}

CarCounter::~CarCounter() {
   delete carCount;
}

// FIXME write copy assignment operator
CarCounter& CarCounter::operator=(const CarCounter& objToCopy) {
   
   if (this != &objToCopy) {           // 1. Don't self-assign
      delete carCount;                  // 2. Delete old dataObject
      carCount = new int;               // 3. Allocate new dataObject
      *carCount = *(objToCopy.carCount); // 4. Copy dataObject
   }
   
   return *this;
}

int main() {
   CarCounter frontParkingLot;
   CarCounter backParkingLot;
   int count;

   cin >> count;

   frontParkingLot.SetCarCount(count);
   backParkingLot = frontParkingLot;

   cout << "Cars counted: " << backParkingLot.GetCarCount();

   return 0;
}