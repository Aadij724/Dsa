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


Node *prev=NULL, *first=NULL, *second=NULL;

// Checking is Tree a BST 

bool isBST( Node* root, int min, int max )
{
    if( root == NULL ) return true;
    
    return( root->key > min && root->key < max &&
            isBST( root->left, min, root->key ) && isBST( root->right, root->key, max ) ); 
}

bool isBSTf( Node* root )
{
    return ( isBST( root, INT8_MIN, INT8_MAX) );
}




// Fixing the BST

void fixBST( Node* root )
{
    if( root == NULL ) return;
    fixBST( root->left);
    if( prev!=NULL && root->key < prev->key )
    {
        if( first == NULL )
            first=prev;
        second=root;
    }
    prev = root;
    fixBST( root->right );
}

void fixBSTf( Node* root )
{
    fixBST( root );
    if( first == NULL )
        return;
    
    int temp;
    temp=first->key;
    first->key=second->key;
    second->key=temp;
}


int main()
{
    Node* root=new Node(20);
    root->left=new Node(60);
    root->left->left=new Node(4);
    root->left->right=new Node(10);
    root->right->left=new Node(8);
    root->right->right=new Node(100);

    cout<<"tree is BST : ";
    cout<<isBSTf(root);

    cout<<"\n\nFixing the BST : ";
    
    cout<<"tree is BST : ";
    cout<< isBSTf(root);
}