#include <bits/stdc++.h>

using namespace std;

struct Node{
    string name;
    string number; 
    Node *left, *right;
    Node(string name, string number){
        this->name = name;
        this->number = number;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node *root, string name, string number){
    if(root == NULL){
        return new Node(name, number);
    }
    else if(name < root->name){
        root->left = insert(root->left, name, number);
    }
    else{
        // if( name > root->name)
        root->right = insert(root->right, name, number);
    }
    return root;
}

void inorder(Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<"-------- Contacts ---------"<<endl;
    cout<<"Name: "<<root->name<<endl;
    cout<<"Number: "<<root->number<<endl;
    inorder(root->right);
}

int main(){
    Node *root = NULL;
    root = insert(root, "Amir", "012456789");
    insert(root, "Zakir", "012456789");
    insert(root, "Bashir", "012456789");
    insert(root, "Monir", "012456789");
    insert(root, "Fariha", "012456789");
    insert(root, "Shafi", "012456789");
    inorder(root);
}