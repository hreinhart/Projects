#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <bits/stdc++.h>

using namespace std;

int minCoins(int *calculatedValues, int i) {

    if (calculatedValues[i] != -1) {
        return calculatedValues[i];
    }

    int numCoins[4];

    numCoins[0] = (i > 25)? minCoins(calculatedValues, i - 25) + 1 : INT_MAX;
    numCoins[1] = (i > 10)? minCoins(calculatedValues, i - 10) + 1: INT_MAX;
    numCoins[2] = (i > 5)? minCoins(calculatedValues, i - 5) + 1: INT_MAX;
    numCoins[3] = (i > 1)? minCoins(calculatedValues, i - 1) + 1: INT_MAX;

    int first = min(numCoins[0], numCoins[1]);
    int second = min(numCoins[2], numCoins[3]);

    calculatedValues[i] = min(first, second);
    return calculatedValues[i];
}

int main() {

    int arr[100000];

    for (int i = 0; i < 100000; i++) {arr[i] = -1;}

    arr[0] = 0; arr[1] = 1; arr[5] = 1; arr[10] = 1; arr[25] = 1;

    cout << "Enter cents" << endl;

    bool anotherOne = true;
    string anotherString;
    for (int count = 0; count < 100000; count++) {
        int centCount;
        cout << count <<": " <<  minCoins(arr, count) << endl;
        sleep(1);
    }

    return 0;
}
