#include <iostream>
#include <cmath> // for sqrt and pow
using namespace std;

class Point {
    double x, y, z; // coordinates

public:
    // Constructor with parameters
    Point(double x_val, double y_val, double z_val) {
        x = x_val;
        y = y_val;
        z = z_val;
    }

    // Member function to calculate distance between two points
    double distance(const Point &other) const {
        return sqrt(pow(x - other.x, 2) +
                    pow(y - other.y, 2) +
                    pow(z - other.z, 2));
    }
};

int main() {
    // Create two points
    Point p1(2.0, 3.0, 4.0);
    Point p2(5.0, 7.0, 9.0);

    // Calculate and print the distance
    double dist = p1.distance(p2);
    cout << "Distance between points: " << dist << endl;

    return 0;
}
