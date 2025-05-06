#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right; 
    
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

static int idx = -1;

Node* buildTree(int preorderArray[]){
    idx++;
    if(preorderArray[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorderArray[idx]);
    root->left = buildTree(preorderArray); 
    root->right = buildTree(preorderArray);

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

void levelOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    queue <Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

int countOfNode(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftNode = countOfNode(root->left);
    int rightNode = countOfNode(root->right);

    return leftNode + rightNode + 1;
}

int main(){
    
    int preorderArray[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = buildTree(preorderArray);

    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;

    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;

    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;

    cout<<"Level Order: ";
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"Count of Nodes: ";
    cout<<countOfNode(root);
    cout<<endl;
}