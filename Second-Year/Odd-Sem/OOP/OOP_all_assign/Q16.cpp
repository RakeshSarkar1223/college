#include <iostream>
using namespace std;

// Function to print a vector (1D array)
void print(int arr[], int size) {
    cout << "Vector elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to print a matrix (2D array)
void print(int arr[][3], int rows, int cols) {
    cout << "Matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Vector (1D array)
    int vec[] = {10, 20, 30, 40, 50};
    int vecSize = sizeof(vec) / sizeof(vec[0]);

    // Matrix (2D array)
    int mat[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Calling overloaded functions
    print(vec, vecSize);     // prints vector
    print(mat, 2, 3);        // prints matrix

    return 0;
}
