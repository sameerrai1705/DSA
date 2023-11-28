#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    
    Node *left , *right;
    int data;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildtree(Node* &root){
    cout<<"Enter data : ";
    int data;
    cin>>data;
    if(data == -1) return NULL;
    root = new Node(data);
    cout<<"\nFor left of "<<root->data<<" ";
    root->left = buildtree(root->left);
    cout<<"\nFor right of "<<root->data<<" ";
    root->right = buildtree(root->right);
    return root;
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrderTransversal(Node *root){
    queue < Node* >q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            if(!q.empty()) q.push(NULL);
            cout<<"\n";
            level++;
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

int main(){
    Node *root = NULL;
    root = buildtree(root);
    preorder(root);
    return 0;
}