#include <iostream>
using namespace std;

//  Overloaded function to find max among three integers
int maxValue(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

//  Overloaded function to find max in an array
int maxValue(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main() {
    // Scenario a: maximum between three integers
    int a = 10, b = 25, c = 17;
    cout << "Maximum among " << a << ", " << b << ", and " << c << " is "
         << maxValue(a, b, c) << endl;

    // Scenario b: maximum element of an array
    int arr[] = {12, 45, 7, 89, 23, 56};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum element in the array is " << maxValue(arr, size) << endl;

    return 0;
}
