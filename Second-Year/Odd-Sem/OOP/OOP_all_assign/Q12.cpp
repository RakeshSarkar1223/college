#include <iostream>
using namespace std;

// Function to copy string using constant pointers
void Strcpy(char * const target, const char * const source) {
    int i = 0;
    while (source[i] != '\0') {
        target[i] = source[i];
        i++;
    }
    target[i] = '\0';  // null-terminate the copied string
}

int main() {
    char source[] = "Hello, World!";
    char target[50];  // target buffer

    Strcpy(target, source);  // call our function

    cout << "Source String: " << source << endl;
    cout << "Copied  String: " << target << endl;

    // Verify source remains unchanged
    cout << "\nVerifying that source is unchanged..." << endl;
    cout << "Source still = " << source << endl;

    return 0;
}
