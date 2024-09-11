#include <iostream>
#include <string>

using namespace std;

class Person {
    protected:
        string name;
        string address;
        string phone;
    
    public:
    void printInfo(){
        cout << "Name: " << name << endl;
        cout << "Adress: " << address << endl;
        cout << "Phone: " << phone << endl;
    }
};

class Instructor : public Person{
    public:
        int instructorID;
    void printInfo(){
        Person::printInfo();
        cout << "ID: " << instructorID << endl;
    }
};

class Student : public Person{
    public:
        int studentID;
    void printInfo(){
        Person::printInfo();
        cout << "ID: " << studentID << endl;
    }

};

int main(){


    return 0;
}
