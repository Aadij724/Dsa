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

void vSumR( Node* root, int hd, map<int, int> &mp )
{
    if( root==NULL ) return ;
    vSumR( root->left, hd - 1, mp );
    mp[hd] += root->key;
    vSumR( root->right, hd + 1, mp );
}

void vSum( Node* root )
{
    map<int, int> mp;
    vSumR( root, 0, mp );
    for( auto sum: mp)
        cout<<sum.second<<" ";
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(50);
    root->left->left=new Node(30);
    root->left->right=new Node(40);

    cout<<"Vertical Sum in Binary Tree : ";
    vSum( root );

    cout<<"\n\n";

    Node* root2=new Node(10);
    root2->left=new Node(15);
    root2->right=new Node(25);
    root2->left->left=new Node(35);
    root2->left->right=new Node(20);
    root2->left->left->left=new Node(40);
    root2->left->right->right=new Node(75);
    root2->left->right->right->right=new Node(80);

    cout<<"Vertical Sum in Binary Tree : ";
    vSum( root2 );
}