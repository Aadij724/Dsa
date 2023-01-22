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

void printKDist1( Node* root, int k )
{
    if( root==NULL ) return;
    
    if( k==0 ){ cout<<root->key<<" "; }
    else
    {
        printKDist1( root->left, k-1 );
        printKDist1( root->right, k-1 );
    }
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->right=new Node(70);

    cout<<"Level order traversal : ";
    printKDist1( root, 2 );

    cout<<"\n\n";

    Node* root2=new Node(10);
    root2->left=new Node(20);
    root2->right=new Node(30);
    root2->left->left=new Node(40);
    root2->left->right=new Node(50);
    root2->right->right=new Node(70);
    root2->right->right->right=new Node(80);

    cout<<"Level order traversal : ";
    printKDist1( root2, 1);
}