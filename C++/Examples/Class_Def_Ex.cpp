#include <iostream>
using namespace std;

class DogLicense {
   public:
      void   SetYear(int yearRegistered);
      void   CreateLicenseNum(int customID);
      int    GetLicenseNum() const;
   private:
      int    licenseYear;
      int    licenseNum;
};

void DogLicense::SetYear(int yearRegistered) {
   licenseYear = yearRegistered;
}

// FIXME: Write CreateLicenseNum()

void DogLicense::CreateLicenseNum(int a){
   licenseNum = (100000 * a) + licenseYear;
}

int DogLicense::GetLicenseNum() const {
   return licenseNum;
}

int main() {
   DogLicense dog1;
   int userYear;
   int userId;

   cin >> userYear;
   cin >> userId;

   dog1.SetYear(userYear);
   dog1.CreateLicenseNum(userId);
   cout << "Dog license: " << dog1.GetLicenseNum() << endl;

   return 0;
