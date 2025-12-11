#include<iostream>

using namespace std;

class Student{
private:
    mutable int age;
    int id;
public:
    Student(){}
    Student(int age, int id){
        this->age = age;
        this->id = id;
    }

    void setAge(int age, int id) const{
        this->age = age;
        // this->id = id; //error id is not moficable 
    }

    void display(){
        cout<<this->age<<" is the age and "<<this->id<<" is the id"<<endl;
    }
};

int main(){
    Student s1(18,1);
    s1.display();
    return 0;
}