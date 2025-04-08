#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return topNode->data;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    void print() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node* temp = topNode;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    cout << "Top element: " << s.top() << endl;
    s.pop();
    s.print();
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
