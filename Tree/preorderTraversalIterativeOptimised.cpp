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

void preorderTraversalItrOpt( Node* root )
{
    if( root==NULL ) return;
    stack<Node* > st;
    Node* curr=root;
    while( curr!=NULL || st.empty()==false )
    {
        while( curr!=NULL )
        {
            cout<< curr->key<<" ";
            if( curr->right != NULL )
                st.push( curr->right );
            curr=curr->left;
        }
        if( st.empty()==false )
        {
            curr=st.top();
            st.pop();
        }
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
    preorderTraversalItrOpt( root );
}