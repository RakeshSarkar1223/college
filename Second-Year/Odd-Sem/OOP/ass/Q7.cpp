#include <iostream>

using namespace std;

int fact(const int n); // Function declaration

int main()
{
    int number;
    cout << "Enter a number to calculate factorial: ";
    cin >> number;

    int ans = fact(number);
    cout << "Factorial of " << number << " is: " << ans << endl;

    return 0;
}

int fact(const int n)
{
    if (n <= 1)
    {
        return n;
    }
    int ans = 1;
    for (int i = n; i >= 1; i--)
    {
        ans *= i;
    }
    
    return ans;
}