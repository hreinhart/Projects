#include <iostream>
using namespace std;

class Vehicle {
   public:
      void SetSpeed(int speedToSet) {
         speed = speedToSet;
      }

      void PrintSpeed() {
         cout << speed;
      }

   private:
      int speed;
};

class Car : public Vehicle {
   public:
      void PrintCarSpeed() {
         cout << "Moving at: ";
         PrintSpeed();
      }
};

class AnimalPowered : public Vehicle {
   public:
      void SetAnimal(string animalToSet) {
         animal = animalToSet;
      }

      void PrintAnimalSpeed() {
         cout << animal << " speed: ";
         PrintSpeed();
      }

   private:
      string animal;
};

int main() {
   Car myCar;
   AnimalPowered wagon;

   myCar.SetSpeed(60);
   wagon.SetSpeed(6);
   wagon.SetAnimal("Camel");

   myCar.PrintCarSpeed();
   cout << endl;
   wagon.PrintAnimalSpeed();

   return 0;
}
