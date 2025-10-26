#include<iostream>

using namespace std;

// int fact(const int *);

// int main(){
//     int n = 5;
//     int *ptr = &n;
//     int ans = fact(ptr);
//     cout<<ans<<endl;
// }

// int fact(const int *n){
//     if(*n <=1){
//         return *n;
//     }
//     int ans = 1;
//     for(int i = *n; i >= 1; i--){
//         ans *= i;
//     }
//     return ans;
// }


long long fact(const int &);
int main(){
    int n = 5;
    cout<<fact(n)<<endl;
}

long long fact(const int &n){
    if(n <= 1) return n;
    int ans = 1;
    for(int i = n; i>= 1; i--){
        ans *= i;
    }
    return ans;
}