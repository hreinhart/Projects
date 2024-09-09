#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

class Foo {
public:
    int v;
    Foo(int v) {
        this->v = v;
    }
    bool operator<(const Foo &rhs) const {
        return this->v < rhs.v;
    }
};

// int myMax(int a, int b) {
//     return a < b ? a : b;
// }
// double myMax(double a, double b) {
//     return a < b ? a : b;
// }
// Foo myMax(const Foo &a, const Foo &b) {
//     return a < b ? a : b;
// }

template <typename T>
T myMax(const T &a, const T &b) {
    return a < b ? b : a;
}
    // return a < b ? b : a;
    // This means if a is less than be return b else return a therefore returning the maximum
    
const char *myMax(const char *&a, const char *&b) {
    return strcmp(a, b) < 0 ? b : a;
}

int main() {
    cout << myMax(1, 2) << endl;
    cout << myMax(2.5, 1.5) << endl;
    cout << myMax(Foo(10), Foo(20)).v << endl;

    const char *b = "bbb";
    const char *a = "aaa";
    cout << myMax(a, b) << endl;

    return 0;
}
