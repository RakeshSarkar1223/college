#include <iostream>
using namespace std;

class Rectangle {
    double length, breadth;

public:
    // Default constructor
    Rectangle() {
        length = 0;
        breadth = 0;
    }

    // Parameterized constructor
    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    // Member function to calculate area
    double area() const {
        return length * breadth;
    }

    // Function to display rectangle details
    void display() const {
        cout << "Length: " << length << ", Breadth: " << breadth
             << " → Area: " << area() << endl;
    }
};

int main() {
    // Create 4 rectangles with different dimensions
    Rectangle r1(5.0, 3.0);
    Rectangle r2(10.5, 4.0);
    Rectangle r3(6.2, 2.5);
    Rectangle r4(8.0, 8.0);

    // Display their areas
    cout << "Areas of rectangles:\n";
    r1.display();
    r2.display();
    r3.display();
    r4.display();

    return 0;
}
