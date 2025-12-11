#include <iostream>
using namespace std;

int main() {
    // Loop variable declared inside the for loop
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }

    cout << endl;

    // Try to access 'i' outside the loop
    // cout << i;  // This will cause an error: 'i' was not declared in this scope

    return 0;
}
