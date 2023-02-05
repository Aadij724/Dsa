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


// Fixing the BST
Node *prev1=NULL, *first1=NULL, *second1=NULL;


void fixBST( Node* root )
{
    if( root == NULL ) return;
    fixBST( root->left);
    if( prev1!=NULL && root->key < prev1->key )
    {
        if( first1 == NULL )
            first1=prev1;
        second1=root;
    }
    prev1 = root;
    fixBST( root->right );
}

void fixBSTf( Node* root )
{
    fixBST( root );
    if( first1 == NULL )
        return;
    
    int temp;
    temp=first1->key;
    first1->key=second1->key;
    second1->key=temp;
}


int main()
{
    Node* root=new Node(20);
    root->left=new Node(60);
    root->right=new Node(80);
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