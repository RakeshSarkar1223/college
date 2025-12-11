#include<iostream> 

using namespace std;

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

//with reference
void swapRef(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int a= 10;
    int b = 30;
    swap(a, b);
    cout<<a<<" "<<b<<endl;
    swapRef(a, b);
    cout<<a<<" "<<b<<endl;
    return 0;
}