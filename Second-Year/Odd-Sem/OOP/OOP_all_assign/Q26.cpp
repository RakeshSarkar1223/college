#include<iostream>

using namespace std;

class Stack{
private:
    int top ;
    int *buffer;
    int size ;
public:
    Stack(int s){
        size = s;
        buffer = new int[size];
        top = -1;
    }

    void push(int e){
        if(top == size - 1){
            cout<<"The stack is full"<<endl;
            return;
        }
        buffer[++top] = e;
    }

    int pop(){
        if(top == -1){
            cout<<"The stack is full"<<endl;
            return -1;
        }
        int ans = buffer[top];
        top--;
        return ans;
    }

    int peek(){
        if(top == -1){
            cout<<"The stack is full"<<endl;
            return -1;
        }
        return buffer[top];
    }
    void disp(){
        for(int i = top; i>= 0; i--){
            cout<<buffer[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    Stack s1(10);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.disp();
    s1.pop();
    s1.disp();
    return 0;
}