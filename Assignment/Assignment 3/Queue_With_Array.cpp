#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
    int front, rear, size;
    int *arr;
    int capacity;

    public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    ~Queue() {
        delete[] arr;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1;
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to peek." << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    cout << "Front element: " << q.peek() << endl;
    
    q.enqueue(60);
    q.display();

    return 0;
}