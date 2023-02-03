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

Node* floor( Node* root, int x )
{
    Node* res=NULL;
    while( root != NULL )
    {
        if( root->key == x )
        {
            res=root;
            return res;
        }

        else if( root->key > x )
            root=root->left;

        else if( root->key < x )
        {
            res=root;
            root=root->right;
        }
    }
    return res;
}

int main()
{
    Node* root=new Node(50);
    root->left=new Node(30);
    root->right=new Node(70);
    root->left->left=new Node(20);
    root->left->right=new Node(40);
    root->right->left=new Node(60);
    root->right->right=new Node(80);
    root->right->left->left=new Node(55);
    root->right->left->right=new Node(65);

    cout<<"Floor value of 58 is : ";
    cout<<(floor( root, 58 ))->key;

    cout<<"\n\nFloor value of 35 is: ";
    cout<<(floor( root, 35 ))->key;
}