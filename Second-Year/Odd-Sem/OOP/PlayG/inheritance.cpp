#include<iostream>

using namespace std;

class Animal{
public:
    Animal(){
        cout<<"sound"<<endl;
    }
    virtual void speek(){
        cout<<"animal"<<endl;
    }
};

class Dog : public Animal{
public:
    Dog(){
        cout<<"ghou"<<endl;
    }
    // void speek(){
    //     cout<<"dog"<<endl;
    // }
};

int main(){
    Animal* d = new Dog();
    d->speek();
    return 0;
}