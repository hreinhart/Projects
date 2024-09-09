#include <string.h>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main(){
    srand(time(0));
    ofstream planetfile;
    string planname;
    cout << "Enter the name of the Planet or the number planet it is" << endl;
    cin >> planname;

    planetfile.open("C:\\Starfinder Campaign\\Planets\\"+ planname);
    
    int type = rand() % 3;
    planetfile << "Type: " << type << endl;;

    planetfile.close();

    return 0;
}