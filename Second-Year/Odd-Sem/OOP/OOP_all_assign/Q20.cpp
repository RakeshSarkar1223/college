#include <iostream>
#include <cmath>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()
using namespace std;

//-------------------------------------
// Class representing a point (x, y)
//-------------------------------------
class Point {
public:
    double x, y;

    // Default + parameterized constructor
    Point(double x_val = 0, double y_val = 0) {
        x = x_val;
        y = y_val;
    }

    // Function to compute Euclidean distance between two points
    double distance(const Point &other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    // Function to randomly set new coordinates
    void randomize() {
        x = rand() % 101;  // random value 0–100
        y = rand() % 101;
    }

    // Display point
    void display() const {
        cout << "(" << x << ", " << y << ")";
    }
};

//-------------------------------------
// Class representing a wireless device
//-------------------------------------
class WirelessDevice {
    static int next_id;  // static counter for unique ID
public:
    int id;          // unique ID
    Point location;  // position
    double range;    // transmission range

    // Constructor — assigns random range and location
    WirelessDevice() {
        id = ++next_id;
        location.randomize();
        range = (rand() % 30) + 20; // random range 20–50
    }

    // Function to move device to new random location
    void move() {
        location.randomize();
    }

    // Function to check if another device is within range
    bool isNeighbor(const WirelessDevice &other) const {
        if (id == other.id) return false; // skip self
        return location.distance(other.location) <= range;
    }

    // Display device info
    void display() const {
        cout << "Device " << id << " | Location: ";
        location.display();
        cout << " | Range: " << range << endl;
    }
};

// Initialize static variable
int WirelessDevice::next_id = 0;

//-------------------------------------
// Main program
//-------------------------------------
int main() {
    srand(time(0)); // seed random generator

    const int N = 10;
    WirelessDevice devices[N];

    cout << "Initial Device Information:\n";
    for (int i = 0; i < N; i++) {
        devices[i].display();
    }

    cout << "\n--- Neighbors before movement ---\n";
    for (int i = 0; i < N; i++) {
        cout << "Device " << devices[i].id << " neighbors: ";
        bool hasNeighbor = false;
        for (int j = 0; j < N; j++) {
            if (devices[i].isNeighbor(devices[j])) {
                cout << devices[j].id << " ";
                hasNeighbor = true;
            }
        }
        if (!hasNeighbor)
            cout << "None";
        cout << endl;
    }

    // Move all devices to new random locations
    for (int i = 0; i < N; i++) {
        devices[i].move();
    }

    cout << "\n--- Neighbors after movement ---\n";
    for (int i = 0; i < N; i++) {
        cout << "Device " << devices[i].id << " neighbors: ";
        bool hasNeighbor = false;
        for (int j = 0; j < N; j++) {
            if (devices[i].isNeighbor(devices[j])) {
                cout << devices[j].id << " ";
                hasNeighbor = true;
            }
        }
        if (!hasNeighbor)
            cout << "None";
        cout << endl;
    }

    return 0;
}
