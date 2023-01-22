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

void inorderIterativeTrversal( Node* root )
{
    stack<Node* > s;
    Node* curr=root;
    while( curr!=NULL || s.empty()==false )
    {
        while( curr!=NULL )
        {
            s.push( curr );
            curr= curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->key<<" ";
        curr=curr->right;
    }
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    
    cout<<"Inorder Traversal( iterative ) : ";
    inorderIterativeTrversal( root );

}