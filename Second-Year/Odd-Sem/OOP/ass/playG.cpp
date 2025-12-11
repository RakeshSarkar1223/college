#include<iostream>
using namespace std;

class Math{
    
public:

    Math(){
    }
    int sum(int a, int b) {
        cout<<"int"<<endl;
        return a + b;
    }
    double sum(double a, double b){
        cout<<"double"<<endl;
        return a + b;
    }
};

int main(){
    Math m1;
    cout<<m1.sum(24.,3.3)<<endl;
    return 0;
    
}