#include <bits/stdc++.h>
using namespace std;

int main(){

    int count = 1;
    float input = -1;
    float output;

    while(input != 0){
        cout << " Input a floating point number." << endl;
        cin >> input;
        if(input == 0){
            break;
        }
        output = abs(input);
        cout << "Input " << count << ": "<< output << endl;
        count++;
    }



    return 0;
}