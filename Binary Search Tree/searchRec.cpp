#include<iostream>
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

bool searchRecursive( Node* root, int x )
{
    if( root == NULL )
        return false;

    else if( root->key > x )
        return searchRecursive( root->left, x);

    else if( root->key < x )
        return searchRecursive( root->right, x);
    
    else
        return true;
}


int main()
{
    Node* root=new Node(15);
    root->left=new Node(5);
    root->right=new Node(20);
    root->left->left=new Node(3);
    root->right->left=new Node(18);
    root->right->right=new Node(80);
    root->right->left->left=new Node(16);

    cout<<"Search in BST for 18 : ";
    cout<<searchRecursive( root, 18 );

    cout<<"\n\nSearch in BST for 80 : ";
    cout<<searchRecursive( root, 80 );

    cout<<"\n\nSearch in BST for 81 : ";
    cout<<searchRecursive( root, 81 );
}