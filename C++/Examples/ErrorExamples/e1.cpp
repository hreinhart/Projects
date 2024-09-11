#include <iostream>

using namespace std;

enum MathErr { noErr, divByZero, genericOverflow };

double divide(double num, double den) {
    if (den == 0)
        throw divByZero;
    return num/den;
}

int main() {
    cout << "Enter two numbers:" << endl;
    double x, y;
    cin >> x >> y;

    try {
        cout << x << "/" << y << " is " << divide(x,y) << endl;
    }
    catch (MathErr x) {
        if (x == divByZero)
            cerr << endl << "**Divide by zero caught." << endl;
        else
            cerr << endl << "**Other error caught." << endl;
    }

    return 0;
}
