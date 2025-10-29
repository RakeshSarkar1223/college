#include<iostream>

using namespace std;

class Complex{
private:
    float real;
    float img;

public:
    Complex(float real = 0, float img = 0){
        this->real = real;
        this->img = img;
    }
    void setReal(float real){
        this->real = real;
    }
    void setImg(float img){
        this->img = img;
    }
    float getReal() const{
        return real;
    }
    float getImg() const {
        return img;
    }
    void disp()const {
        cout<<real<<" + i*"<<img<<endl;
    }

    Complex addComplex(const Complex &c2){
        Complex ans;
        ans.setReal(real + c2.getReal());
        ans.setImg(img + c2.getImg());
        return ans;
    }
};

int main(){
    Complex c1(1,2);
    c1.disp();
    c1.setImg(4);
    c1.disp();
    Complex c2(3,4);
    Complex c3 = c1.addComplex(c2);
    c3.disp();
    return 0;
}