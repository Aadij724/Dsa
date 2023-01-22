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

int height( Node* root )
{
    if( root==NULL ) return 0;
    return 1 + max( height(root->left), height( root->right) );
}

int diameterPrint( Node* root )
{
    int maxDia = height(root->left) + height(root->right) + 1;
    int dia;
    queue<Node* > q;
    q.push( root );
    Node* curr;
    while( q.empty()==false )
    {
        curr=q.front();
        q.pop();
        //cout<<curr->key;
        dia= height( curr->left ) + height(curr->right) + 1;
        if( dia > maxDia )
            maxDia=dia;

        if( curr->left != NULL ) q.push( curr->left );
        if( curr->right != NULL ) q.push( curr->right );
    }
    return maxDia;
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->left->left=new Node(60);
    root->right->right=new Node(50);

    cout<<"Diameter of Binary Tree: ";
    cout<<diameterPrint( root );

    Node* root2=new Node(10);
    root2->left=new Node(20);
    root2->right=new Node(60);
    root2->left->left=new Node(30);
    root2->left->right=new Node(80);
    root2->left->left->left=new Node(40);
    root2->left->left->right=new Node(50);
    root2->left->left->left->left=new Node(60);
    root2->left->right->right=new Node(90);
    root2->left->right->right->right=new Node(18);

    cout<<"\n\nDiameter of Binary Tree: ";
    cout<<diameterPrint( root2 );
}