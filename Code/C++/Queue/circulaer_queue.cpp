#include <bits/stdc++.h>

using namespace std;

class CircularQueue{
    public:
    int front;
    int rear;
    int* arr;
    int capacity, currSize;

    
    CircularQueue(int size){
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        currSize = 0;
    }

    void enqueue(int value){
        if(currSize == capacity){
            cout<<"CQ is Full"<<endl;
            return;
        }
        rear = (rear+1)%capacity;
        arr[rear] = value;
        currSize++;
    }

    void dequeue(){
        if(empty()){
            cout<<"CQ is Empty."<<endl;
            return;
        }
        front = (front+1)%capacity;
        currSize--;
    }

    int f(){
        if(empty()){
            cout<<"CQ is Empty."<<endl;
            return -1;
        }
        return arr[front];
    }

    int r(){
        if(empty()){
            cout<<"CQ is Empty."<<endl;
            return -1;
        }
        return arr[rear];
    }

    bool empty(){
        return currSize == 0;
    }

    void display(){
       
    }
};

int main(){
    CircularQueue cq(3);
    cq.enqueue(4);
    cq.enqueue(5);
    cq.enqueue(6);
    cq.enqueue(7);
}