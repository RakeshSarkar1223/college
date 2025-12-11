#include <iostream>
using namespace std;

class Vector {
    int size;
    int *arr;

public:
    // Default constructor
    Vector(int s = 3) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    // Parameterized constructor
    Vector(int s, int values[]) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = values[i];
    }

    // Copy constructor
    Vector(const Vector &v) {
        size = v.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = v.arr[i];
    }

    // Destructor
    ~Vector() {
        delete[] arr;
    }

    // Display function
    void display() const {
        cout << "[ ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "]";
    }

    // Operator overloading for addition
    Vector operator+(const Vector &v) const {
        if (size != v.size) {
            cout << "Error: Vectors must have same size for addition!\n";
            return *this;
        }
        Vector result(size);
        for (int i = 0; i < size; i++)
            result.arr[i] = arr[i] + v.arr[i];
        return result;
    }

    // Operator overloading for subtraction
    Vector operator-(const Vector &v) const {
        if (size != v.size) {
            cout << "Error: Vectors must have same size for subtraction!\n";
            return *this;
        }
        Vector result(size);
        for (int i = 0; i < size; i++)
            result.arr[i] = arr[i] - v.arr[i];
        return result;
    }

    // Equality check
    bool operator==(const Vector &v) const {
        if (size != v.size)
            return false;
        for (int i = 0; i < size; i++)
            if (arr[i] != v.arr[i])
                return false;
        return true;
    }

    // "Less than" based on sum of elements
    bool operator<(const Vector &v) const {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < size; i++) sum1 += arr[i];
        for (int i = 0; i < v.size; i++) sum2 += v.arr[i];
        return sum1 < sum2;
    }

    // "Greater than" based on sum of elements
    bool operator>(const Vector &v) const {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < size; i++) sum1 += arr[i];
        for (int i = 0; i < v.size; i++) sum2 += v.arr[i];
        return sum1 > sum2;
    }
};

//---------------------------------------
// Main function to test the class
//---------------------------------------
int main() {
    int a1[] = {1, 2, 3};
    int a2[] = {4, 5, 6};
    int a3[] = {1, 2, 3};

    Vector v1(3, a1);
    Vector v2(3, a2);
    Vector v3(3, a3);

    cout << "v1 = "; v1.display(); cout << endl;
    cout << "v2 = "; v2.display(); cout << endl;
    cout << "v3 = "; v3.display(); cout << endl;

    // Test addition
    cout << "\nv1 + v2 = ";
    Vector sum = v1 + v2;
    sum.display();

    // Test subtraction
    cout << "\n\nv2 - v1 = ";
    Vector diff = v2 - v1;
    diff.display();

    // Test equality
    cout << "\n\nv1 == v3 ? " << (v1 == v3 ? "True" : "False") << endl;
    cout << "v1 == v2 ? " << (v1 == v2 ? "True" : "False") << endl;

    // Test comparison
    cout << "\nIs v1 < v2 ? " << (v1 < v2 ? "Yes" : "No") << endl;
    cout << "Is v2 > v1 ? " << (v2 > v1 ? "Yes" : "No") << endl;

    return 0;
}
