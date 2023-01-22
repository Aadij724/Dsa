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

Node* insertIterative( Node* root , int x )
{
    
}



void inorderTraversalRec(Node* head)
{
    if( head!=NULL )
    {
        inorderTraversalRec( head->left );
        cout<<head->key<<" ";
        inorderTraversalRec( head->right );
    }
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->right->left=new Node(12);
    root->right->right=new Node(18);

    cout<<"Inorder Traversal ( Before Insert ) : ";
    inorderTraversalRec( root );

    cout<<"\n\nInsertion of 20 in BST : ";
    root=insertIterative( root, 20 );

    cout<<"\n\nInorder Traversal ( After Insert ) : ";
    inorderTraversalRec( root );
}