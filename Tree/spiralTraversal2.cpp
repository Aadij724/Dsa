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

void spiralPrint2( Node* root )
{
    stack<Node* > st1;
    stack<Node* > st2;

    Node* curr;

    st1.push( root );
    while( st1.empty()==false || st2.empty()==false )
    {
        while( st1.empty()==false )
        {
            curr=st1.top();
            st1.pop();
            cout<<curr->key<<" ";
            if( curr->left != NULL ) st2.push( curr->left );
            if( curr->right != NULL ) st2.push( curr->right );
        }

        cout<<endl;

        while( st2.empty()==false )
        {
            curr=st2.top();
            st2.pop();
            cout<<curr->key<<" ";
            if( curr->right != NULL ) st1.push( curr->right );
            if( curr->left != NULL ) st1.push( curr->left );
        }
        
        cout<<endl;
    }
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->left->left->left=new Node(8);
    root->left->left->right=new Node(9);
    root->right->left->left=new Node(10);
    root->right->left->right=new Node(11);
    
    cout<<"Spiral Print: \n";
    spiralPrint2( root );
}