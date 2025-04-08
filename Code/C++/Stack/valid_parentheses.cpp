#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char value) {
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


    void push(char value) {
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
};

bool isValid(string str){
    Stack st;
    for(int i=0; i<str.size(); i++){
        // For opening parentheses
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            st.push(str[i]);
        }
        // For closing parentheses
        else{
            if(st.isEmpty()){
                return false;
            }
            else{
                if((st.top()=='(' && str[i]==')') ||
                   (st.top()=='{' && str[i]=='}') ||
                   (st.top()=='[' && str[i]==']')){
                        st.pop();
                   }
                   else{ // No match
                    return false;
                   }
            }
        }
    }

    return st.isEmpty();

}

int main() {
    Stack s;
    string str;
    cout<<"Enter String: ";
    cin>>str;
    if(isValid(str)){
        cout<<"Valid."<<endl;
    }
    else{
        cout<<"Invalid."<<endl;
    }


    return 0;
}
