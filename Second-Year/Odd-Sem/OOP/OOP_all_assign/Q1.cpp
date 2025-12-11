#include <iostream>
using namespace std;

// ===========================================================
// a) Flexible variable declaration
// ===========================================================
void flexible_variable_declaration() {
    cout << "Start of program\n";
    int a = 5; // declared here
    cout << "a = " << a << endl;

    if (a == 5) {
        int b = 10; // declared inside block
        cout << "b = " << b << endl;
    }
}

// ===========================================================
// b) C++ style of input/output
// ===========================================================
void cpp_style_io() {
    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "You are " << age << " years old." << endl;
}

// ===========================================================
// c) C++ style type names
// ===========================================================
void cpp_style_typenames() {
    typedef unsigned int uint;
    uint x = 25;
    cout << "Unsigned integer: " << x << endl;
}

// ===========================================================
// d) Enumeration values
// ===========================================================
void enumeration_values() {
    enum Weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
    Weekday today = Wednesday;
    cout << "Day number: " << today << endl;
}

// ===========================================================
// e) Type casting
// ===========================================================
void type_casting() {
    int a = 5, b = 2;
    double result = static_cast<double>(a) / b;
    cout << "Result = " << result << endl;
}

// ===========================================================
// f) Use of scope resolution operator (::)
// ===========================================================
int value = 10; // global variable
void scope_resolution_operator() {
    int value = 5; // local variable
    cout << "Local value: " << value << endl;
    cout << "Global value: " << ::value << endl; // :: accesses global variable
}

// ===========================================================
// g) Constants
// ===========================================================
void constants_demo() {
    const double PI = 3.14159;
    cout << "PI = " << PI << endl;
    // PI = 3.14; // Error: cannot modify const
}

// ===========================================================
// h) Constants and #define
// ===========================================================
#define MAX 100
void constants_and_define() {
    const int SIZE = 10;
    cout << "MAX = " << MAX << endl;
    cout << "SIZE = " << SIZE << endl;
}

// ===========================================================
// i) Constants and Pointers
// ===========================================================
void constants_and_pointers() {
    int x = 10, y = 20;
    const int* ptr = &x; // pointer to constant
    // *ptr = 15; // not allowed
    ptr = &y; // allowed
    cout << *ptr << endl;

    int* const ptr2 = &x; // constant pointer
    *ptr2 = 30; // allowed
    // ptr2 = &y; // not allowed
    cout << *ptr2 << endl;
}

// ===========================================================
// j) References
// ===========================================================
void references_demo() {
    int a = 10;
    int &ref = a; // reference to a
    cout << "a = " << a << ", ref = " << ref << endl;
    ref = 20; // changes a also
    cout << "a = " << a << ", ref = " << ref << endl;
}

// ===========================================================
// k) Constants and references
// ===========================================================
void constants_and_references() {
    int x = 10;
    const int &ref = x; // const reference
    cout << "ref = " << ref << endl;
    // ref = 20; // Error
}

// ===========================================================
// l) Usage of references
// ===========================================================
void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void usage_of_references() {
    int x = 5, y = 10;
    swapValues(x, y);
    cout << "x = " << x << ", y = " << y << endl;
}

// ===========================================================
// m) Functions that return by reference
// ===========================================================
int& maxValue(int &a, int &b) {
    return (a > b) ? a : b;
}

void return_by_reference() {
    int x = 5, y = 10;
    maxValue(x, y) = 100; // modifies the larger variable
    cout << "x = " << x << ", y = " << y << endl;
}

// ===========================================================
// n) Inline function
// ===========================================================
inline int square(int x) {
    return x * x;
}

void inline_function() {
    cout << "Square of 5 = " << square(5) << endl;
}

// ===========================================================
// o) Inline function and macro
// ===========================================================
#define SQUARE(x) ((x) * (x))
inline int squareInline(int x) { return x * x; }

void inline_function_and_macro() {
    cout << "Macro square: " << SQUARE(5+1) << endl; // expands to ((5+1)*(5+1))
    cout << "Inline square: " << squareInline(5+1) << endl; // safer
}

// ===========================================================
// p) Function overloading
// ===========================================================
void display(int a) { cout << "Integer: " << a << endl; }
void display(double b) { cout << "Double: " << b << endl; }
void display(string s) { cout << "String: " << s << endl; }

void function_overloading() {
    display(10);
    display(10.5);
    display("Hello");
}

// ===========================================================
// q) Default values of function parameters
// ===========================================================
void showDetails(string name, int age = 18) {
    cout << "Name: " << name << ", Age: " << age << endl;
}

void default_values_of_parameters() {
    showDetails("Rakesh");
    showDetails("Suman", 22);
}

// ===========================================================
// MAIN FUNCTION
// ===========================================================
int main() {
    cout << "\n===== C++ Concept Demonstrations =====\n";

    // Uncomment one at a time to test:

    // flexible_variable_declaration();
    // cpp_style_io();
    // cpp_style_typenames();
    // enumeration_values();
    // type_casting();
    // scope_resolution_operator();
    // constants_demo();
    // constants_and_define();
    // constants_and_pointers();
    // references_demo();
    // constants_and_references();
    // usage_of_references();
    // return_by_reference();
    // inline_function();
    // inline_function_and_macro();
    // function_overloading();
    // default_values_of_parameters();

    cout << "\n===== End of Program =====\n";
    return 0;
}
