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

int getMaxIterative( Node* root )
{
    if( root==NULL ) return INT8_MIN;
    queue<Node*> q;
    int maxi=INT8_MIN;
    q.push( root );
    Node* curr;
    while( q.empty()==false )
    {
        curr=q.front();
        q.pop();
        if( curr->key > maxi )
            maxi=curr->key;

        if( curr->left != NULL )
            q.push( curr->left );
        if( curr->right != NULL )
            q.push( curr->right );
    }
    return maxi;
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(30);
    root->right=new Node(40);
    root->left->left=new Node(80);
    root->left->left->right=new Node(70);
    root->right->left=new Node(60);
    root->right->right=new Node(20);

    cout<<"Maximum in the tree : "<< getMaxIterative( root );
}