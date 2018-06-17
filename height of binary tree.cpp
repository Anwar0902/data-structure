#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};

struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;

    return (node);
}
int height(Node* root)
{
    if(root==NULL)
        return 0;
    int l=height(root->left);
    int h=height(root->right);
    return 1+max(l,h);
}
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
   // root->left->right->left = newNode(6);
    //root->left->right->right = newNode(7);
    //root->left->left->right = newNode(8);
   // root->left->left->right->left = newNode(9);
    cout<<height(root);
}
