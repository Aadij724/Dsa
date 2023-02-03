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

Node* ceil( Node* root, int x )
{
    Node* res=NULL;
    while( root != NULL )
    {
        if( root->key == x )
        {
            res = root;
            return res;
        }
        
        else if( root->key < x )
            root = root->right;
        
        else if( root->key > x )
        {
            res = root;
            root= root->left;
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
    root->right->right=new Node(78);
    root->right->left->left=new Node(55);
    root->right->left->right=new Node(65);

    cout<<"Ceil value of 70 : ";
    cout<< (ceil( root, 70))->key ;

    cout<<"\n\nCeil value of 63 : ";
    cout<< (ceil( root, 63))->key ;
    
    cout<<"\n\nCeil value of 15 : ";
    cout<< (ceil( root, 15))->key ;
    
    
}