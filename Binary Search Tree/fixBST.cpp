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

void inorderTraversal( Node* root )
{
    if( root!=NULL )
    {
        inorderTraversal( root->left );
        cout<< root->key<<" ";
        inorderTraversal( root->right );
    }
}

Node *prev=NULL, *first=NULL, *second=NULL;

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

    cout<<"Inorder Traversal : ";
    inorderTraversal( root );
    
    cout<<"\n\nFixing the BST...";
    fixBSTf( root );

    cout<<"\n\nInorder Traversal : ";
    inorderTraversal( root );
}