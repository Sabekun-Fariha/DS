#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

};

class LinkedList{

    Node* head;
    Node* tail;

    public:
    LinkedList(){
        head = tail = NULL; 
    }
    
    // Push Front
    void push_front(int val){
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = tail = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    
    // Push Back
    void push_back(int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = tail = newNode;
        }else{
             tail->next = newNode;
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
            cout<<"Empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
    void pop_back(){
        if(head == NULL){
            cout<<"Empty"<<endl;
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
    
    void insert(int val, int pos){
        if(pos < 0){
            cout<<"Invalid Position"<<endl;
            return;
        }
        if(pos == 0){
            push_front(val);
            return;
        }
        Node* temp = head;
        Node* newNode = new Node(val);
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    int search(int key){
        Node* temp = head;
        int pos = 0;
        while(temp != NULL){
            if(temp->data == key){
                return pos;
            }
            temp = temp->next;
            pos++;
        }
        return -1;
    }
    
    int specified_pos(int pos){
        Node* temp = head;
        int i = 0;
        while(i != pos){
            temp = temp->next;
            i++;
        }
        return temp->data;
    }
    void reverse(){
       Node* current = head;
       Node* prev = NULL;
       Node* New = NULL;
       
       while(current != NULL){
        New = current->next;
        current->next = prev;
        prev = current;
        current = New; 
       }
       head = prev;
    }
};

int main()
{
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.print();
    ll.reverse();
    ll.print();
}