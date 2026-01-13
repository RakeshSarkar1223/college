#include<iostream>

using namespace std;

class A{
private:
    int a;
public:
    A(int val = 0){
        a = val;
    }

};

class B{
private:
    int b;
public:
    B(int val = 0){
        b = val;
    }
};

class Sample{
private:
    static int s;
    const int c;
    int x;
public:
    Sample(int y = 0): c(y++){
        // c = y++; // wrong
        s = x = y;
    }
    
    void increment(){
        s++;
        x++;
    }
    
    void show(){
        cout<<s<<" "<<x<<" "<<c<<endl;
    }
};

int Sample::s = 0;

int main(){
    Sample ob1(5), ob2(6);
    ob1.show();
    ob2.show();
    ob1.increment();
    ob2.show();
}