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

void levelOrderTraversalLine2( Node* root )
{
    if( root==NULL ) return;
    queue<Node* > q;
    q.push( root );
    Node* curr;
    while( q.empty()==false )
    {
        int count=q.size();
        for( int i=0; i<count; i++ )
        {
            curr=q.front();
            q.pop();
            cout<< curr->key<<" ";
            if( curr->left != NULL ) q.push( curr->left );
            if( curr->right != NULL ) q.push( curr->right );
        }
        cout<<"\n";
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
    levelOrderTraversalLine2( root );
}