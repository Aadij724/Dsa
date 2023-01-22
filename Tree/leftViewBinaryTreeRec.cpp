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


int maxLevel=0;

void printLeft( Node* root, int level )
{
    if( root == NULL ) return ;
    if( maxLevel < level )
    {
        cout<<( root->key )<<" ";
        maxLevel=level;
    }
    printLeft( root->left, level + 1);
    printLeft( root->right, level + 1);
}

void printLeftView( Node* root )
{
    printLeft( root, 1 );
}

int main()
{
    Node* root=new Node(10); 
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);

    cout<<"Leftview of Binary Tree : ";
    printLeftView( root );

}