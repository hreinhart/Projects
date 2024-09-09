#ifndef MyArray_h
#define MyArray_h

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

#endif
