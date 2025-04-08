#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    Queue() {
        front = rear = nullptr;
        size = 0;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1;
        }
        int item = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek." << endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void removeNegatives() {
        Node* temp = front;
        Node* prev = nullptr;
        while (temp) {
            if (temp->data < 0) {
                if (temp == front) {
                    front = front->next;
                    if (front == nullptr) rear = nullptr;
                    delete temp;
                    temp = front;
                } else {
                    prev->next = temp->next;
                    if (temp == rear) rear = prev;
                    delete temp;
                    temp = prev->next;
                }
                size--;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(-3);
    q.enqueue(4);
    q.enqueue(-5);
    
    cout << "Q: ";
    q.display();
    
    q.removeNegatives();
    
    cout << "Q after removing negatives: ";
    q.display();

    return 0;
}