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

int getMaxRec( Node* root )
{
    if( root==NULL )
        return INT8_MIN;

    else
        return max( root->key, max( getMaxRec( root->left ), getMaxRec( root->right ) ) );
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(30);
    root->right=new Node(40);
    root->left->left=new Node(80);
    root->left->left->right=new Node(70);
    root->right->left=new Node(60);
    root->right->right=new Node(20);

    cout<<"Maximum in the tree : "<< getMaxRec( root );
}