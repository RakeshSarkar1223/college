#include<iostream>

using namespace std;

class Sample{
private:
    int a;
public:
    Sample(){a = 0;}
    Sample(int a){
        this->a = a;
    }
    void show(){
        cout<<this->a<<endl;
    }
    
    Sample& operator +=(int n){
        this->a += n;
        return *this;
    }

    Sample& operator++(){//prefix ++a
        ++a;
        return *this;
    }

    Sample operator++(int){//postfix
        Sample temp = *this;
        a++;
        return temp;
    }

    friend Sample operator *(Sample s1, int n);

    friend ostream& operator<<(ostream &out, const Sample &s);

    friend istream& operator>>(istream &in, Sample &s);

    // friend Sample& operator++(Sample &s);
};
Sample operator *(Sample s1, int n){
    Sample temp;
    temp.a = s1.a * n;
    return temp;
}

ostream& operator<<(ostream &out, const Sample &s){
    out<<s.a<<endl;
    return out;
}

istream& operator>>(istream &in, Sample &s){
    in>>s.a;
    return in;
}


// Sample& operator++(Sample &s){// this is the code of prefix sum that is ++a but this style should not be used;
//     s.a++;
//     return s;
// }


int main(){
    Sample s1(5), s2;
    s2 = s1 * 10;
    s2 += 4;
    s2.show();
    Sample s3(45);
    cout<<s3;
    // s3.show();
    cin>>s3;
    ++s3;
    operator<<(cout, s3);

    return 0;
}