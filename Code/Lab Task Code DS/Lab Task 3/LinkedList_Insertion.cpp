#include <bits/stdc++.h>

using namespace std;

struct Node{
    
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

    public:
    LinkedList(){
        head = nullptr;
    }

    void insert(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
        }
       else{
        Node* tail = head;
        while(tail->next != nullptr){
            tail = tail->next;
        }
        tail->next = newNode;
       }
    }

    void print(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    int n, v, i;
    cin>>n;
    LinkedList ll;
    for(i=0; i<n; i++){
        cin>>v;
        ll.insert(v);
    }
    ll.print();
    return 0;
}