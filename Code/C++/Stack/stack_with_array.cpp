#include <bits/stdc++.h>
using namespace std;

class Stack{
    private:
    int *arr;
    int capacity;
    int topIndex;

    public:
    // Constructor
    Stack(int size){
        capacity = size;
        arr = new int [capacity];
        topIndex = -1;
    }

    // Destructor
    ~Stack(){
        delete[] arr; 
    }
    void push(int val){
        if(topIndex == capacity-1){
            cout<<"The Stack is full."<< endl;
        }
        arr [++topIndex] = val; 

    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack is empty."<<endl;
            return;
        }
        topIndex--;
    }
    
    int top(){
       if(isEmpty()){
        cout<< "Stack is Empty."<< endl;
        return -1;
       }
       return arr[topIndex];
    }

    bool isEmpty(){
       return topIndex==-1;
    }

    void print(){
        if(isEmpty()){
            cout<<"Stack is Empty."<<endl;
            return;
        }
        cout<<"Stack elements: ";
        for(int i=0; i<=topIndex; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
};

int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    cout<<"Top Element: "<<s.top()<<endl;
    s.pop();
    s.print();
    cout<<"Top Element: "<<s.top()<<endl;
}
