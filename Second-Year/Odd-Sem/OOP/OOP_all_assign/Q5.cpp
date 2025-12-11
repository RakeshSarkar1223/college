#include <iostream>
using namespace std;

int main() {
    cout << "Celsius\tFahrenheit" << endl;
    cout << "-------------------" << endl;

    for (int celsius = 0; celsius <= 100; celsius += 10) {
        double fahrenheit = (celsius * 9.0 / 5.0) + 32; // declared where first used
        cout << celsius << "\t" << fahrenheit << endl;
    }

    return 0;
}
