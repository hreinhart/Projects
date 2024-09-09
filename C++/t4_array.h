#ifndef MyArray_h
#define MyArray_h

template <typename T>
class MyArray {
public:
    int size;
    T *data;

    MyArray(int s = 100);
    MyArray(const MyArray &src);
    T &operator[](int index);
};

#include "t4_array.cpp"

#endif
