#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

class Queue{
    Node* front;
    Node* rear;

    public:
    Queue(){
        front = rear = NULL;
    }

    void enqueue(int value){
        Node* newNode = new Node(value);
        if(front == NULL){
            front = rear = newNode;
        }
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue(){
        if(front == NULL){
            cout<<"Empty list."<<endl;
            return;
        }
        else{
            Node* temp = front;
            cout<<"Popped element: "<<front->data<<endl;
            front = front->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void peek(){
        if(front == NULL){
            cout<<"Empty Queue.";
        }
        else{
            cout<<"Peek element: "<<front->data<<endl;
        }
    }

    void display(){
        Node* temp = front;
        cout<<"Queue: ";
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.display();
    q.peek();
    q.dequeue();
    q.display();
    q.peek();
    q.dequeue();
    q.display();
    q.peek();
    q.enqueue(5);
    q.display();
    q.peek();
}