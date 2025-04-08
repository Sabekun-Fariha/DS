#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = nullptr;
    }
};

class DoublyLinkedList{
    private:
    Node* head;
    Node* tail;

    public:
    DoublyLinkedList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void pop_front(){
        if(head == NULL){
            cout<<"Empty List."<<endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        if(head!=NULL){
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        if(head == NULL){
            cout<<"Empty List."<<endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if(tail!=NULL){
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }
};

int main(){
    DoublyLinkedList dl;
    dl.push_front(3);
    dl.push_front(2);
    dl.push_front(1);
    dl.print();
    dl.push_back(4);
    dl.push_back(5);
    dl.print();
    dl.pop_front();
    dl.print();
    dl.pop_back();
    dl.print();

}