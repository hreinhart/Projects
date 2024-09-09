#include <iostream>

using namespace std;

// class MyArray {
// private:
//     int size;
//     int *data;
// public:
//     MyArray(int s = 100) {
//         this->size = s;
//         this->data = new int[size];
//     }
//     MyArray(const MyArray &src) {
//         this->size = src.size;
//         this->data = new int[size];
//         for (int i = 0; i < size; i++) {
//             this->data[i] = src.data[i];
//         }
//     }
//     int &operator[](int index) {
//         return data[index];
//     }
// };

template <typename T>
class MyArray {
public:
    int size;
    T *data;

    MyArray(int s = 100) {
        this->size = s;
        this->data = new T[size];
    }
    MyArray(const MyArray &src) {
        this->size = src.size;
        this->data = new T[size];
        for (int i = 0; i < size; i++) {
            this->data[i] = src.data[i];
        }
    }
    T &operator[](int index) {
        return data[index];
    }
};

int main() {
    // MyArray array(10);
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
