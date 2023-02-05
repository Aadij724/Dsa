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
        key = x;
        left=NULL;
        right=NULL;
    }
};

int count=0;

void printKth( Node* root, int k )
{
    if( root!=NULL )
    {
        printKth( root->left, k);
        count++;
        if( count==k )
        {
            cout<< root->key;
            return;
        }
        printKth( root->right, k);
    }
}

int main()
{
    Node* root= new Node(50);
    root->left = new Node(20);
    root->right = new Node(100);
    root->left->left = new Node(10);
    root->left->right = new Node(40);
    root->right->left = new Node(70);
    root->right->right = new Node(120);
    root->right->left->right = new Node(80);

    cout<<"3rd smallest in the tree is : ";
    printKth( root, 3 );

    cout<<"\n\n";
    count=0;
    cout<<"5th smallest in the tree is : ";
    printKth( root, 5 );
}