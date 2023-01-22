#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int key;
        Node* left;
        Node* right;

    Node(int x)
    {
        key=x;
        left=NULL;
        right=NULL;
    }
};

void spiralPrint( Node* root )
{
    if( root==NULL ) return;
    queue<Node*> q;
    stack<int> st;
    bool reverse=false;

    q.push(root);
    while( q.empty()==false )
    {
        int count=q.size();
        for( int i=0; i<count; i++)
        {
            Node* curr=q.front();
            q.pop();
            if( reverse )
                st.push( curr->key );
            else
                cout<<curr->key<<" ";
            if( curr->left != NULL ) q.push( curr->left );
            if( curr->right != NULL ) q.push( curr->right );
        }
        if( reverse )
        {
            while( st.empty()== false )
            {
                cout<< st.top()<<" ";
                st.pop();
            }
        }
        reverse= !reverse;
        cout<<endl;
    }
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    root->right->left->left=new Node(60);
    root->right->left->right=new Node(70);
    root->right->right->right=new Node(80);

    cout<<"Spiral Traversal: \n";
    spiralPrint( root );
}