#include<iostream>

using namespace std;

class Complex{
private:
    int real;
    int img;
public:
    Complex(){}
    Complex(int real, int img){
        this->img = img;
        this->real = real;
    }

    Complex operator +(Complex &c2){
        Complex c3;
        c3.real = this->real + c2.real;
        c3.img = this->img + c2.img;
        return c3;
    }
    void view(){
        cout<<this->real<<" + i"<<this->img<<endl;
    }
};

int main(){
    Complex c1(2,3);
    Complex c2(4,5);
    Complex c3 = c1.operator+(c2);
    c3.view();
    return 0;
}