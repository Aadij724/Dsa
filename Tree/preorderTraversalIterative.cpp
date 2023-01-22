#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int key;
        Node* left;
        Node* right;

    Node( int x )
    {
        key=x;
        left=NULL;
        right=NULL;
    }
};

void preorderIterativeTraversal( Node* root )
{
    if( root==NULL ) return;
    stack<Node* > s;
    s.push( root );
    Node* curr;
    while( s.empty()==false )
    {
        curr=s.top();
        cout<<curr->key <<" ";
        s.pop();
        if( curr->right != NULL )
            s.push( curr->right );
        if( curr->left != NULL )
            s.push( curr->left );
    }
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->left=new Node(60);

    cout<<"Preorder traversal( iterative ) : ";
    preorderIterativeTraversal( root );
}