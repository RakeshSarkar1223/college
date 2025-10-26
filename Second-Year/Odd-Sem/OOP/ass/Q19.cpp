#include<iostream>
using namespace std;
class rectangle{
    private:
    double x, y;
    public:
    rectangle(double x, double y){
        this->x = x;
        this->y = y;
    }
    double area() const{
        return x * y;
    }
};

int main(){
    rectangle r1(12,2);
    cout<<r1.area()<<endl;
    return 0;
}