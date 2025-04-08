#include <bits/stdc++.h>

using namespace std;

class Queue{
    private:
    int* arr;
    int front;
    int rear;
    int size;

    public:
    Queue(int capacity){
        size = capacity;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int value){
        if (rear == size-1){
            cout<<"Overflow."<<endl;
        }
        else if(empty()){
            front = rear = 0;
            arr[rear] = value;
        }
        else{
            rear++;
            arr[rear] = value;
        }

    }

    void dequeue(){
        if(empty() || (front>rear)){
            cout<<"Empty Queue."<<endl;
        }
        else{
            cout<<"Removed element: "<<arr[front]<<endl;
            front++;
        }
    }

    bool empty(){
        if((front==-1 && rear == -1)){
            return true;
        }
        return false;
    }

    void peek(){
        if(empty()){
            cout<<"Empty list."<<endl;
        }
        else{
            cout<<"Peek element: "<<arr[front]<<endl;
        }
    }

    void display(){
        if(empty() || (front>rear)){
            cout<<"Empty list."<<endl;
        }
        else{
            cout<<"Queue: ";
            for(int i=front; i<=rear; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    Queue q(6);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.display(); // 5 6 7
    q.peek(); // 5
    q.dequeue(); // 5
    q.peek(); // 6
    q.display(); // 6 7
    q.dequeue(); // 6
    q.peek(); // 7
    q.display(); // 7
    q.enqueue(8); 
    q.display(); // 7 8
    q.dequeue(); // 7
    q.display(); // 8
    q.dequeue(); // 8
    q.display(); // empty
    q.dequeue(); // empty
}