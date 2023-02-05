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

int prev = 0;

bool isBst( Node* root )
{
    if( root==NULL ) return true;
    if( isBst(root->left) == false ) return false;
    if( root->key <= prev ) return false;
    prev = root->key;
    return isBst( root->right );
}

int main()
{
    Node* root=new Node(20);
    root->left=new Node(8);
    root->right=new Node(30);
    root->right->left=new Node(18);
    root->right->right=new Node(35);

    cout<<"Tree is BST : ";
    cout<< isBst( root );

    Node* root2=new Node(80);
    root2->left=new Node(70);
    root2->right=new Node(90);
    root2->left->left=new Node(60);
    root2->left->right=new Node(75);
    root2->right->left=new Node(85);
    root2->right->right=new Node(100);

    prev=INT8_MIN;
    cout<<"\n\nTree is BST : ";
    cout<<isBst( root2 );
}