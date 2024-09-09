#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(){

    ifstream file;
    string words;
    file.open("C:\\CS\\C\\input_example.txt");

    while(file >> words){
        cout << words << " ";
    }

    file.close();
    return 0;
}