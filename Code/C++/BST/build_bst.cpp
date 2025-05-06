#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildBST(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
    }
    if(val < root->data){
        root->left = buildBST(root->left, val);
    }
    else if(val > root->data){
        root->right = buildBST(root->right, val);
    }
    return root;
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    else if(key < root->data){
        return search(root->left, key);
    }
    else if(key > root->data){
        return search(root->right, key);
    }
}

int main(){
    int arr[] = {5, 1, 3, 6, 7, 8};
    int size = sizeof(arr)/sizeof(arr[0]);

    Node* root = NULL;

    for(int i =0; i<size; i++){
        root = buildBST(root, arr[i]);
    }


    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;

    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;

    int key;
    cout<<"Enter a key to search: ";
    cin>>key;
    if(search(root, key)){
        cout<<"Found.";
    }else{
        cout<<"Not Found.";
    }
}