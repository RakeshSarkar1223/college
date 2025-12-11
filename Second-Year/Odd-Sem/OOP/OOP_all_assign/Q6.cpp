#include <iostream>
using namespace std;

int main() {
    const double PI = 3.14159;   // defining constant PI

    double radius;               // variable for radius
    cout << "Enter the radius of the circle: ";
    cin >> radius;

    double area = PI * radius * radius;  // area formula
    cout << "Area of the circle = " << area << endl;

    return 0;
}
