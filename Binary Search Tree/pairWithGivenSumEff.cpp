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

bool isPairSum( Node* root, int sum, unordered_set<int> &s)
{
    if( root==NULL ) return false;
    if( isPairSum( root->left, sum, s ) == true )
        return true;

    if( s.find( sum - root->key ) != s.end() )
        return true;
    else
        s.insert( root->key );

    return isPairSum( root->right, sum, s);
}

bool isPairSumF( Node* root, int sum )
{
    unordered_set<int> s;
    return isPairSum( root, sum, s );
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(20);
    root->right->left=new Node(16);
    root->right->right=new Node(40);

    cout<<"Pair with sum 36 is present in BST : ";
    cout<<isPairSumF( root, 36 );

    cout<<"\n\n";

    Node* root2=new Node(10);
    root2->left=new Node(8);
    root2->right=new Node(20);
    root2->left->left=new Node(4);
    root2->left->right=new Node(9);
    root2->right->left=new Node(11);
    root2->right->right=new Node(30);
    root2->right->right->left=new Node(25);

    cout<<"Pair with sum 33 is present in BST : ";
    cout<<isPairSumF( root2, 33 );

    cout<<"\n\n";

    Node* root3=new Node(20);
    root3->left=new Node(8);
    root3->right=new Node(40);
    root3->right->left=new Node(35);

    cout<<"Pair with sum 49 is present in BST : ";
    cout<<isPairSumF( root3, 49 );
}