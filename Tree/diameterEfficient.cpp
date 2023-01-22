#include<iostream>
using namespace std;

int res=0;

class Node
{
    public:
        int key;
        Node* left;
        Node* right;

    Node( int x )
    {
        left=NULL;
        right=NULL;
    }
};

int height( Node* root )
{
    if( root==NULL ) return 0;
    int lh = height( root->left );
    int rh = height( root->right );
    res = max( res, lh + rh + 1 );

    return 1 + max( lh, rh );
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);
    root->right->left->left=new Node(60);
    root->right->right->right=new Node(70);

    cout<<"Height of tree :"<<height( root );
    cout<<"Diameter of tree :"<<res;
    
}