#include <iostream>
using namespace std;

class MyVector {
private:
    int n;          // number of elements
    int capacity;   // total allocated space
    int *arr;       // dynamic array

    // helper to increase capacity
    void expandCapacity() {
        if (capacity == 0)
            capacity = 1;
        else
            capacity *= 2;

        int *newArr = new int[capacity];
        for (int i = 0; i < n; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

public:
    // Constructors
    MyVector() {
        n = 0;
        capacity = 1;
        arr = new int[capacity];
    }

    MyVector(int size, int value = 0) {
        n = size;
        capacity = size * 2;
        arr = new int[capacity];
        for (int i = 0; i < n; i++)
            arr[i] = value;
    }

    // ✅ push_back
    void push_back(int value) {
        if (n >= capacity)
            expandCapacity();
        arr[n++] = value;
    }

    // ✅ pop_back
    void pop_back() {
        if (n == 0) {
            cout << "Vector is empty!" << endl;
            return;
        }
        n--;
    }

    // ✅ insert at specific position
    void insert(int pos, int value) {
        if (pos < 0 || pos > n) {
            cout << "Index out of bound!" << endl;
            return;
        }

        if (n >= capacity)
            expandCapacity();

        for (int i = n; i > pos; i--)
            arr[i] = arr[i - 1];

        arr[pos] = value;
        n++;
    }

    // ✅ erase (remove element at given index)
    void erase(int pos) {
        if (pos < 0 || pos >= n) {
            cout << "Index out of bound!" << endl;
            return;
        }
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }

    // ✅ resize (change size of vector)
    void resize(int newSize, int value = 0) {
        if (newSize < n) {
            n = newSize;
        } else if (newSize > n) {
            if (newSize > capacity) {
                while (capacity < newSize)
                    expandCapacity();
            }
            for (int i = n; i < newSize; i++)
                arr[i] = value;
            n = newSize;
        }
    }

    // ✅ clear (remove all elements)
    void clear() {
        n = 0;
    }

    // ✅ at (safe access)
    int at(int index) const {
        if (index < 0 || index >= n) {
            cout << "Index out of range!" << endl;
            return -1;
        }
        return arr[index];
    }

    // ✅ front and back
    int front() const { return (n > 0 ? arr[0] : -1); }
    int back() const { return (n > 0 ? arr[n - 1] : -1); }

    // ✅ size, capacity, empty
    int size() const { return n; }
    int getCapacity() const { return capacity; }
    bool empty() const { return n == 0; }

    // ✅ display elements
    void display() const {
        cout << "[ ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "]";
        cout << "  (size=" << n << ", cap=" << capacity << ")";
        cout << endl;
    }

    // Destructor
    ~MyVector() {
        delete[] arr;
    }
};

int main() {
    MyVector v(3, 5); // initialize with size=3, value=5
    v.display();

    v.push_back(10);
    v.push_back(20);
    v.display();

    v.insert(2, 99);
    v.display();

    v.erase(1);
    v.display();

    v.pop_back();
    v.display();

    cout << "Element at 1: " << v.at(1) << endl;
    cout << "Front: " << v.front() << ", Back: " << v.back() << endl;

    v.resize(8, 7);
    v.display();

    v.clear();
    cout << "After clear, empty? " << (v.empty() ? "Yes" : "No") << endl;

    return 0;
}
