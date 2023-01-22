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

int getSizeRec( Node* root )
{
    if( root==NULL ) return 0;
    else
    {
        return 1 + getSizeRec( root->left ) + getSizeRec( root->right );
    }
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->right=new Node(60);

    cout<<"Size of Tree : "<< getSizeRec( root );

}