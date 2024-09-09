#include <iostream>

using namespace std;

void fun() {
    try {
        throw "hello";
        //throw 0; // try me
    }
    catch (const char *str) {
        cerr << "Caught in fun(): " << str << endl;
        throw; //re-throws exception str
    }
}

int main() {
    try {
        fun();
    }
    catch (const char *e) {
        cerr << "Caught in main(): " << e << endl;
    }

    return 0;
}
