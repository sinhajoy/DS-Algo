#include "bits/stdc++.h"

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left =NULL;
        right =NULL;
    }
};

void inorder(node* root){
    inorder(root->left);
    cout<<root->data<<" "<<endl;
    inorder(root->right);
}
void preorder(node* root){
    cout<<root->data<<" "<<endl;
    preorder(root->left);
    preorder(root->right);

}
void postorder(node* root){
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" "<<endl;
}

int main()
{ 

    struct node* root =  new node(1);
    root->left = new node(2);
    root->right =new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    inorder(root);
    preorder(root);
    postorder(root);


    return 0;
}