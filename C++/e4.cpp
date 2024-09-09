#include <iostream>

using namespace std;

enum MathErr { noErr, divByZero, genericOverflow };

double divide(double num, double den) {
    if (den == 0)
        throw divByZero;
    return num/den;
}

class MyIndexError {
private:
    int badIndex;
    string message;
public:
    MyIndexError(int i, string msg) {
        this->badIndex = i;
        this->message = msg;
    }
    int getBadIndex() { return badIndex; }
    string getMessage() { return message; }
};

class MyArray {
private:
    int size;
    int *data;
public:
    MyArray(int s = 100) {
        this->size = s;
        this->data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }
    int &operator[](int index) {
        if (index < 0 || index >= this->size) {
            throw MyIndexError(index, "Index out of bounds");
        }
        return data[index];
    }
};

void fun2(MyArray &array) {
    try {
        double x = divide(array[100], array[0]);
        //double x = divide(array[1], array[0]); // try me
    }
    catch (MathErr) {
        cerr << "Math Error caught" << endl;
    }
}

void fun1(MyArray &array) {
    try {
        fun2(array);
    }
    catch (MyIndexError &e) {
        cerr << endl << "Error at index " << e.getBadIndex()
            << ": " << e.getMessage() << endl;
    }
}

int main() {
    MyArray array(10);
    fun1(array);
    return 0;
}
