#include<iostream>
using namespace std;

class Student{
private:
    int id;
    mutable char *name;

public:
    Student(char *name){
        this->name = name;
        this->id = 0;
    }
    int getID() const{
        return id;
    }
    char* getName() const {
        name = "Rakesh";
        return name;
    }
};

int main(){
    char *name = "Rakesh";
    Student s1(name);
    cout<<s1.getName()<<endl;
    return 0;
}
