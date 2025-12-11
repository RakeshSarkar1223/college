#include<iostream>

using namespace std;

class frind1{
private:
    string name ;
public:
    frind1(){}
    frind1(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }
};

class frind2: public frind1{
private:
    int id;
public:
    frind2(int id){
        this->id = id;
    }
    int getId(){
        return id;
    }
};


class frind3{
private:
    int age;
public:
    frind3(int age){
        this->age = age;
    }

    friend class f4;
};