#include <iostream>
using namespace std;

// Function to swap two numbers using references
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;

    cout << "Before swapping:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    swap(x, y);  // call the function

    cout << "After swapping:" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
