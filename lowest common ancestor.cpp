// C++ program for Quick Sort on Singly Linled List
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
struct Node
{
    int key;
    struct Node *left, *right;
};
Node * newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}
void printinorder(Node *head)
{
    if(!head)
        return;
    printinorder(head->left);
    cout<<head->key<<" ";
    printinorder(head->right);
}
bool lca(Node *head,vector<int>&path,int data)
{
    if(!head)
        return false;
    path.push_back(head->key);
    if(head->key==data)
        return true;
    if(lca(head->left,path,data) || lca(head->right,path,data))
        return true;
    path.pop_back();
    return false;

}
int findlca(Node *head,int first,int second)
{
    vector<int>path1,path2;
    lca(head,path1,first);
    lca(head,path2,second);
    int i;
    for(i=0;i<min(path1.size(),path2.size());i++)
    {
        if(path1[i]!=path2[i])
            break;
    }
    return path1[i-1];
}
int main()
{
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printinorder(root);
    cout << "\nLCA(4, 5) = " << findlca(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findlca(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findlca(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findlca(root, 2, 4);
}
