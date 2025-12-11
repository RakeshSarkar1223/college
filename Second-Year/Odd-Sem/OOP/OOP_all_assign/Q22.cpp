#include <iostream>
using namespace std;

class IntArray {
    int *arr;   // pointer to dynamically allocated array
    int size;   // number of elements

public:
    // Constructor
    IntArray(int s, const int values[] = nullptr) {
        size = s;
        arr = new int[size];
        if (values != nullptr) {
            for (int i = 0; i < size; i++)
                arr[i] = values[i];
        } else {
            for (int i = 0; i < size; i++)
                arr[i] = 0;
        }
    }

    // Copy Constructor (deep copy)
    IntArray(const IntArray &other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }

    // Destructor
    ~IntArray() {
        delete[] arr;
    }

    // Display array elements
    void display() const {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Add two arrays
    IntArray add(const IntArray &other) const {
        if (size != other.size) {
            cout << "Error: Array sizes must be equal for addition!" << endl;
            return *this;
        }
        IntArray result(size);
        for (int i = 0; i < size; i++)
            result.arr[i] = arr[i] + other.arr[i];
        return result;
    }

    // Reverse the array
    void reverse() {
        for (int i = 0; i < size / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }

    // Sort the array (simple bubble sort)
    void sortArray() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    int values[] = {1, 2, 3};
    IntArray arr1(3, values);

    cout << "arr1 elements: ";
    arr1.display();

    // Copy constructor creates a deep copy
    IntArray arr2 = arr1;

    cout << "arr2 (copy of arr1): ";
    arr2.display();

    // Reverse arr2
    arr2.reverse();

    cout << "\nAfter reversing arr2:" << endl;
    cout << "arr1: ";
    arr1.display();

    cout << "arr2: ";
    arr2.display();

    return 0;
}
