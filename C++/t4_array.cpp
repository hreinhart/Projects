template <typename T>
MyArray<T>::MyArray(int s) {
    this->size = s;
    this->data = new T[size];
}

template <typename T>
MyArray<T>::MyArray(const MyArray &src) {
    this->size = src.size;
    this->data = new T[size];
    for (int i = 0; i < size; i++) {
        this->data[i] = src.data[i];
    }
}

template <typename T>
T &MyArray<T>::operator[](int index) {
    return data[index];
}
