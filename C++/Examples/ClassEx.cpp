#include <iostream>

using namespace std;

class Person {
public:
    string id;
    string first;
    string last;
    string email;
    string phone;
    string city;
    string state;
    string postalCode;
};

int main(){

    string key = "id";
    Person p;
    p.id = "fuk";
    if(key == "id"){
    cout << p.id;}
    return 0;
}
