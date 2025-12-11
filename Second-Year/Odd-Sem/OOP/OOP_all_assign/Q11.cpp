#include<iostream>

using namespace std;

int fact(const int &a){
    int ans = 1;
    for(int i = 1;i <= a; i++){
        ans *= i;
    }
    return ans;
}

int main(){
    int a = 4;
    int ans = fact(a);
    cout<<ans<<endl;
    return 0;
}