#include <iostream>
using namespace std;

// Helper function to manually copy strings
void copyString(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Swap function (normal parameters)
void swapStrings(char a[], char b[]) {
    char temp[100];

    // Copy a → temp
    copyString(temp, a);
    // Copy b → a
    copyString(a, b);
    // Copy temp → b
    copyString(b, temp);

    cout << "\nInside swapStrings (without reference):" << endl;
    cout << "a = " << a << ", b = " << b << endl;
}

//  Swap function using pointers (reference-style)
void swapStringsRef(char *a, char *b) {
    char temp[100];
    int i = 0;

    // Copy a → temp
    while (a[i] != '\0') {
        temp[i] = a[i];
        i++;
    }
    temp[i] = '\0';

    // Copy b → a
    i = 0;
    while (b[i] != '\0') {
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';

    // Copy temp → b
    i = 0;
    while (temp[i] != '\0') {
        b[i] = temp[i];
        i++;
    }
    b[i] = '\0';
}

int main() {
    char str1[100] = "Hello";
    char str2[100] = "World";

    cout << "Before swapping:" << endl;
    cout << "str1 = " << str1 << ", str2 = " << str2 << endl;

    // Call the first version
    swapStrings(str1, str2);
    cout << "\nAfter swapStrings (without reference):" << endl;
    cout << "str1 = " << str1 << ", str2 = " << str2 << endl;

    // Call the second version
    swapStringsRef(str1, str2);
    cout << "\nAfter swapStringsRef (with reference using pointers):" << endl;
    cout << "str1 = " << str1 << ", str2 = " << str2 << endl;

    return 0;
}
