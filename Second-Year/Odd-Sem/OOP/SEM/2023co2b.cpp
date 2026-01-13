#include<iostream>

using namespace std;

class Weight{
private:
    int kilogram, gram;
public:
    Weight(int kg = 0, int g = 0){
        kilogram = kg;
        gram = g;
    }
    Weight(const Weight& other ){
        this->kilogram = other.kilogram;
        this->gram = other.gram;
    }

    void show() const{
        cout<<kilogram<<","<<gram<<endl;
    }
    
    Weight subtract(const Weight &other){
        Weight temp = *this;
        temp.kilogram = this->kilogram - other.kilogram;
        temp.gram = this->gram - other.gram;
        return temp;
    }
    
    friend Weight add(Weight w1, Weight w2);
    
};