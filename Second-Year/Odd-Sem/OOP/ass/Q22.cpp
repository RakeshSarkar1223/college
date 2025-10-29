#include<iostream>

using namespace std;

class IntArray{
private:
    int size;
    int *arr;
public:
    IntArray(int size, int values[] = nullptr){
        this->size = size;
        arr = new int[size];
        if(values != nullptr){
            for(int i = 0; i< size ; i++){
                arr[i] = values[i];
            }
        }
        else {
            for(int i = 0; i< size; i++){
                arr[i] = 0;
            }
        }
    }
    IntArray(const IntArray &arr2){
        size = arr2.size;
        arr = new int[size];
        for(int i = 0; i< size ; i++){
            arr[i] = arr2.arr[i];
        }
    }

    IntArray add(const IntArray &arr2){
        if(this->size != arr2.size){
            cout<<"size mismatched"<<endl;
            return IntArray(0);
        }

        IntArray result(this->size);
        for(int i = 0; i< size; i++){
            result.arr[i] = this->arr[i] + arr2.arr[i];
        }
        return result;
    }

    void sortArr(){
        for(int i = 0; i< size - 1; i++){
            for(int j = 0; j < size - i - 1; j++){
                if(arr[j] > arr[j + 1]){
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }


    IntArray rev(){
        IntArray temp(size);
        for(int i = 0; i < size ; i++){
            temp.arr[size - i - 1] = arr[i];
        }
        return temp;
    }
    void display(){
        for(int i = 0; i< size ; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    ~IntArray(){
        delete[] arr;
    }
    
};


int main(){
    int v[] = {1,2,3};
    IntArray arr1(3,v);
    int u[] = {2,3,4};
    IntArray arr2(3,u);
    IntArray arr3 = arr1.add(arr2);
    arr3.display();

    int w[] = {4,2,5,2,7,5};
    IntArray arr4(6, w);
    arr4.display();
    arr4.sortArr();
    cout<<endl;
    arr4.display();

    IntArray arr5 = arr2.rev();
    arr5.display();
    return 0;
}