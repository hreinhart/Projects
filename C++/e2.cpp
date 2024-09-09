#include <iostream>
#include <string>

using namespace std;

void someFunction() {
    throw 1.4; // double (not a float)
    //throw "hello"; // const char * // try me
    //throw string("hello"); // try me
}

int main() {
    try {
        someFunction();
    }
    catch (int x) {
        cerr << "Caught INTEGER: " << x << endl;
    }
    catch (string s) {
        cerr << "Caught STRING: " << s << endl;
    }
    catch (...) {
        cerr << "Caught generic exception" << endl;
    }

    return 0;
}
