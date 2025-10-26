#include<iostream>
using namespace std;

inline int add(int a, int b, int c){
    return (a + b + c);
}

int main(){
    int ans = add(12, 2, 3);
    cout<<ans<<endl;
}