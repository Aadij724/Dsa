#include<iostream>
using namespace std;

class Node
{
    public:
        int key;
        Node* left;
        Node* right;
        int lCount;
    
    Node( int x )
    {
        key=x;
        left=NULL;
        right=NULL;
        lCount=0;
    }
};


Node* insertIterative( Node* root , int x )
{
    Node* temp = new Node(x);
    Node* parent = NULL;
    Node* curr = root;

    while( curr!=NULL )
    {
        parent=curr;
        if( curr->key > x )
            curr=curr->left;
        else if( curr->key < x )
            curr = curr->right;
        else
            return root;
    }

    parent = NULL;
    curr = root;

    while( curr!=NULL )
    {
        parent=curr;
        if( curr->key > x )
        {
            (curr->lCount)++;
            curr=curr->left;
        }
        else if( curr->key < x )
            curr = curr->right;
        else
            return root;
    }

    if( parent==NULL )
        return temp;
    if( parent->key > x )
        parent->left = temp;
    
    else
        parent->right = temp;
    return root;
}



void printKth( Node* root, int k )
{
    if( (root->lCount + 1)==k )
        cout<< root->key;
    else if( (root->lCount + 1) > k )
        printKth( root->left, k );
    else
        printKth( root->right, k-(root->lCount)-1 );
}

int main()
{
    Node* root=new Node( 50 );
    root = insertIterative( root, 20 );
    root = insertIterative( root, 10 );
    root = insertIterative( root, 40 );
    root = insertIterative( root, 100 );
    root = insertIterative( root, 70 );
    root = insertIterative( root, 120 );
    root = insertIterative( root, 60 );
    root = insertIterative( root, 80 );
    
    cout<<"3rd smallest node is : ";
    printKth( root, 3 );
    
    cout<<"\n\n";
    cout<<"6th smallest node is : ";
    printKth( root, 6 );
    
}