#include <iostream>
using namespace std;

// Inline function to add three integers
inline int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    int x = 10, y = 20, z = 30;  

    int sum = add(x, y, z);  // call inline function

    cout << "The sum of " << x << ", " << y << ", and " << z << " is " << sum << endl;

    return 0;
}
