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

void printLeft( Node* root )
{
    if( root == NULL ) return;
    queue<Node*> q;
    q.push(root);
    while( q.empty()==false )
    {
        int count=q.size();
        for( int i=0; i<count; i++)
    }
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);


}