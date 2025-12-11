#include <iostream>
using namespace std;

// Function to calculate factorial
long long factorial(const int n) {   // parameter declared as const
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    long long result = factorial(num);  // function call
    cout << "Factorial of " << num << " = " << result << endl;

    return 0;
}
