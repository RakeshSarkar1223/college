#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float img;

public:
    // Setter functions
    void setReal(float r) {
        real = r;
    }

    void setImg(float i) {
        img = i;
    }

    // Getter functions
    float getReal() {
        return real;
    }

    float getImg() {
        return img;
    }

    // Function to display complex number
    void disp() {
        if (img >= 0)
            cout << real << " + " << img << "i" << endl;
        else
            cout << real << " - " << -img << "i" << endl;
    }

    // Function to sum two complex numbers
    Complex sum(Complex c2) {
        Complex temp;
        temp.real = real + c2.real;
        temp.img = img + c2.img;
        return temp;
    }
};

int main() {
    Complex c1, c2, c3;

    // Set values for c1 and c2
    c1.setReal(3.5);
    c1.setImg(2.5);

    c2.setReal(1.5);
    c2.setImg(-4.5);

    // Sum of c1 and c2 stored in c3
    c3 = c1.sum(c2);

    // Display all complex numbers
    cout << "First Complex Number: ";
    c1.disp();

    cout << "Second Complex Number: ";
    c2.disp();

    cout << "Sum of the two Complex Numbers: ";
    c3.disp();

    return 0;
}
