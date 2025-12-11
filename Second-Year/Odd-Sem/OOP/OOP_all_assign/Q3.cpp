#include <iostream>
using namespace std;

int main() {
    int n = 6;   // we need factorials up to 6
    long long fact = 1; // to store factorial value

    for (int i = 1; i <= n; i++) {
        fact = fact * i; // calculate factorial
        cout << i << "! = " << fact << endl;
    }

    return 0;
}
