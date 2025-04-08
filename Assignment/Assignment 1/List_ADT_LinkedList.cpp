#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

class LinkedList{
    private:
    Node* head;
    int length;

    public:
    LinkedList(){
        head = nullptr;
        length = 0;
    }

    void add(int item){
        Node* newNode = new Node(item);
        if(head == nullptr){
            head = newNode;
        }else{
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
            length++;
        }
    }

    void addbegin(int item) {
        Node* newNode = new Node(item);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void addanypos(int pos, int item) {
        if (pos < 0 || pos > length) return;
        if (pos == 0) addbegin(item);
        else {
            Node* newNode = new Node(item);
            Node* temp = head;
            for (int i = 0; i < pos - 1; i++) temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
    }

    void removefirst() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void removelast() {
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; }
        else {
            Node* temp = head;
            while (temp->next->next) temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
        }
        length--;
    }

    void display() {
        Node* temp = head;
        while (temp!=nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse() {
        Node* prev = nullptr, *current = head, *next = nullptr;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void sort() {
        if (!head || !head->next) return;
        for (Node* i = head; i; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->data > j->data) swap(i->data, j->data);
            }
        }
    }
};

int main() {
    LinkedList list;
    list.add(5);
    list.add(10);
    list.add(15);
    cout << "List after adding elements: ";
    list.display();

    list.addbegin(1);
    cout << "List after adding at beginning: ";
    list.display();

    list.addanypos(2, 7);
    cout << "List after adding at specific position: ";
    list.display();

    list.removefirst();
    cout << "List after removing first element: ";
    list.display();

    list.removelast();
    cout << "List after removing last element: ";
    list.display();

    list.reverse();
    cout << "List after reversing: ";
    list.display();

    list.sort();
    cout << "List after sorting: ";
    list.display();
    
    return 0;
}