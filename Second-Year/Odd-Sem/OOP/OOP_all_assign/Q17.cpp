#include <iostream>
using namespace std;

// Inline function with default values
inline int add(int a, int b = 0, int c = 0) {
    return a + b + c;
}

int main() {
    int x = 5, y = 10, z = 15;

    cout << "Calling add(x, y, z): " << add(x, y, z) << endl;  // 3 arguments
    cout << "Calling add(x, y): " << add(x, y) << endl;        // 2 arguments
    cout << "Calling add(x): " << add(x) << endl;              // 1 argument

    return 0;
}
