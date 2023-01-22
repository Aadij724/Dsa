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

void leftViewBinaryTree( Node* root )
{
    if( root==NULL ) return;
    queue<Node* > q;
    q.push( root );
    Node* curr;
    int flag=0;
    while( q.empty()==false )
    {
        int count=q.size();
        flag=0;
        for( int i=0; i<count; i++ )
        {
            curr=q.front();
            q.pop();
            if( flag==0 )
            {
                cout<< curr->key<<" ";
                flag=1;
            }
            if( curr->left != NULL ) q.push( curr->left );
            if( curr->right != NULL ) q.push( curr->right );
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
    root->right->right=new Node(60);

    cout<<"Left View of Binary tree : ";
    leftViewBinaryTree( root );

    cout<<"\n\n";

    Node* root2=new Node(10);
    root2->left=new Node(50);
    root2->right=new Node(60);
    root2->right->left=new Node(70);
    root2->right->right=new Node(20);
    root2->right->left->right=new Node(8);

    cout<<"Left View of Binary tree : ";
    leftViewBinaryTree( root2 );

}