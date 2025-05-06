#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
}; 

void inorder(Node* root){ // Left Root Right
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(Node *root){ // Root Left Right
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root){ // Left Right Root
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main(){
    struct Node *root = new Node (5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(8);

    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
    
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder: ";
    postorder(root); 
    cout<<endl;

}