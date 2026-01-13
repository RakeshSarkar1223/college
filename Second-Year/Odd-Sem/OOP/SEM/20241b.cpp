#include<iostream>

using namespace std;


int highestD(int *no, int *max){
    
    if((*no) == 0){
        return (*max);
    }

    int rem = (*no) % 10;
    *max = rem > *max ? rem : *max;
    (*no) /= 10;
    return highestD(no, max);
}

bool isFibo(int digit){
    int a = 0;
    int b = 1;
    if(digit == 0 || digit == 1) return true;
    while(b <= digit){
        if(digit == b) return true;
        int temp = a + b;
        a = b;
        b = temp;
    }
    return false;
}

bool finalFunction(int no){
    int max = -1;
    int highD = highestD(&no, &max);
    return isFibo(highD);
}

int main(){
    // int a = 77855;
    // int max = -1; 
    // int ans = highestD(&a, &max);
    // cout<<ans<<endl;

    int a ;
    cin>>a;
    cout<<finalFunction(a)<<endl;
    return 0;
}