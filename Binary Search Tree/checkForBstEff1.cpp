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

int main()
{
    Node* root=new Node(80);
    root->left=new Node(70);
    root->right=new Node(90);
    root->left->left=new Node(60);
    root->left->right=new Node(75);
    root->right->left=new Node(85);
    root->right->right=new Node(100);

    cout<<"Tree is a BST :"<< isBSTf( root );
    
    Node* root2=new Node(20);
    root->left=new Node(8);
    root->right=new Node(30);
    root->right->left=new Node(18);
    root->right->right=new Node(35);

    cout<<"\n\nTree is a BST :"<< isBSTf( root );
    

    cout<<"\n\n( 1 means true, 0 means false)";
}