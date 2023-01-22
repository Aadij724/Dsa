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

void levelOrderTraversalLine1( Node* root )
{
    if( root==NULL ) return;
    queue<Node* > q;
    q.push( root );
    q.push( NULL );
    Node* curr;
    while( q.size() > 1 )
    {
        curr=q.front();
        q.pop();
        if( curr==NULL )
        {
            cout<<"\n";
            q.push( NULL );
            continue;
        }
        cout<< curr->key <<" ";
        if( curr->left != NULL ) q.push( curr->left );
        if( curr->right != NULL ) q.push( curr->right );
    }
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->right=new Node(60);

    cout<<"Level Order Traversal |line by line| : \n";
    levelOrderTraversalLine1( root );
}