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

    void pop_in_specified_pos(int pos){
        if(head == NULL){
            cout<<"Empty"<<endl;
            return;
        }
        Node* temp = head;
        Node* del = head;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    void middle(){
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<"Middle value of the list: "<<slow->data<<endl;
    }

    void insert_after_middle(int val){
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* temp = slow->next;
        Node* newNode = new Node(val);
        slow->next = newNode;
        newNode->next = temp;
    }

    void insert_before_middle(int val){
        Node* slow = head;
        Node* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* temp = head;
        while(temp->next!=slow){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        temp->next = newNode;
        newNode->next = slow;
    }

    void reverse(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = nullptr;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

int main()
{
   LinkedList ll;
   ll.push_front(5);
   ll.push_front(4);
   ll.push_front(3);
   ll.push_front(2);
   ll.push_front(12);

   ll.print();
   
   ll.insert(9, 0);
   
   ll.print();
   
   cout<<"Value at position 3: "<<ll.specified_pos(3)<<endl;
   ll.middle();

   ll.insert_after_middle(27);
   ll.print();

   ll.insert_before_middle(13);
   ll.print();

   ll.pop_in_specified_pos(2);
   ll.print();

   ll.reverse();
   cout<<"After Reverse:"<<endl;
   ll.print();
   
}
