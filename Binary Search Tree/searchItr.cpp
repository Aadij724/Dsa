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

bool searchIterative( Node* root, int x )
{
    while( root != NULL )
    {
        if( root->key > x )
            root = root->left;
        else if( root->key < x )
            root = root->right;
        else
            return true;
    }
    return false;
}

int main()
{
    Node* root=new Node(15);
    root->left=new Node(5);
    root->right=new Node(20);
    root->left->left=new Node(3);
    root->right->right=new Node(80);
    root->right->left=new Node(18);
    root->right->left->left=new Node(16);

    cout<<"Search in BST for 3 : ";
    cout<<searchIterative( root, 3 );

    cout<<"\n\nSearch in BST for 19 : ";
    cout<<searchIterative( root, 19 );
}