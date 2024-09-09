#include <iostream>

#include "t4_array.h"

using namespace std;

// compile with: g++ t4_main.cpp
int main() {
    MyArray<int> array(10);
    for (int i = 0; i < array.size; i++) {
        array.data[i] = 10*i;
    }

    cout << "[";
    for (int i = 0; i < 10; i++) {
        cout << " " << array[i];
    }
    cout << " ]" << endl;

    return 0;
}
