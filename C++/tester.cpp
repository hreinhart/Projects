#include <iostream>
using namespace std;
#include "CircularDynamicArray.cpp"

int main(){

    CircularDynamicArray<int> A;
    for(int i = 0; i<100; i++){
        A.addFront(i*2);
        A.addEnd(i*4);
    }
    for(int i = 0; i < A.length(); i++){
        cout << A[i] << " ";
    }
    cout << endl;
    cout << "Here " << A.QuickSelect(10)<< endl;
    cout << "Sorted " << endl;
    A.stableSort();
    for(int i = 0; i < A.length(); i++){
        cout << A[i] << " ";
    }
    cout << endl;
    cout << "Here part 2 " << A.WCSelect(10)<< endl;




    return 0; 
}