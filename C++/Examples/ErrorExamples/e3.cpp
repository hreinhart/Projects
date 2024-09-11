#include <iostream>
#include <string>

using namespace std;

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

int main() {
    MyArray array(10);
    try {
        cout << "Element 10 is " << array[10] << endl;
    }
    catch (MyIndexError e) {
    //catch (MyIndexError &e) { // try me
    //catch (MyIndexError) { // try me
    //catch (...) { // try me
        cerr << endl << "Error at index " << e.getBadIndex()
            << ": " << e.getMessage() << endl;
    }

    return 0;
}
