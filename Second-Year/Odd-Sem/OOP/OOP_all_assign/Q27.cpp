#include<iostream>

using namespace std;

class Queue{
private:
    int *data;
    int front, rear;
    int size;
public:
    Queue(int s){
        size = s;
        data = new int[size];
        front = -1;
        rear = -1;
    }

    void add(int e){
        if((rear + 1) % size == front){
            cout<<"The queue is full"<<endl;
            return ;
        }
        if(front == -1){
            front = 0;
        }
        rear = (rear + 1)  % size;
        data[rear] = e;
    }

    int remove(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int ele = data[front];
        if(front == rear){
            front = rear = -1;//only one element left
        }
        front = (front + 1) % size;
        return ele;
    }

    void disp(){
        
    }
};