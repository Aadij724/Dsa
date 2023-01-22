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


int getSizeIterative( Node* root )
{
    if( root==NULL ) return 0;
    queue<Node*> q;
    int count=0;
    q.push( root );
    Node* curr;
    while( q.empty()==false )
    {
        curr=q.front();
        q.pop();
        count++;
        if( curr->left != NULL )
            q.push( curr->left );
        if( curr->right != NULL )
            q.push( curr->right );
    }
    return count;
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->right=new Node(60);

    cout<<"Size of Tree : "<< getSizeIterative( root );

}