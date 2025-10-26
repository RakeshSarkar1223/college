#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

inline int add_inline(int a, int b) {
    return a + b;
}

int add_normal(int a, int b) {
    return a + b;
}

int main() {
    const int N = 100000000; // 10 crore iterations
    int x = 10, y = 20, z;

    // Measure inline time
    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        z = add_inline(x, y);
    }
    auto end1 = high_resolution_clock::now();

    // Measure non-inline time
    auto start2 = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        z = add_normal(x, y);
    }
    auto end2 = high_resolution_clock::now();

    auto inline_time = duration_cast<microseconds>(end1 - start1).count();
    auto normal_time = duration_cast<microseconds>(end2 - start2).count();

    cout << "Inline function time: " << inline_time << " microseconds\n";
    cout << "Normal function time: " << normal_time << " microseconds\n";

    return 0;
}
