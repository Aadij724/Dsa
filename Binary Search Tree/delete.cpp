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


void inorderTra( Node* root)
{
    if( root != NULL)
    {
        inorderTra( root->left );
        cout<<root->key<<" ";
        inorderTra( root->right );
    }
}


Node* getSuccessor( Node *curr )
{
    curr = curr->right;
    while( curr != NULL && curr->left != NULL )
        curr = curr->left;
    return curr;
}

Node* delNode( Node* root, int x )
{
    if( root == NULL ) return root;
    if( root->key > x)
        root->left = delNode( root->left, x );
    else if( root->key < x)
        root->right = delNode( root->right, x);
    else
    {
        if( root->left == NULL )
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if( root->right == NULL )
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getSuccessor( root );
            root->key = succ->key;
            root->right = delNode( root->right, succ->key );
        }
        return root;
    }
    
}

int main()
{
    Node* root=new Node(50);
    root->left=new Node(30);
    root->right=new Node(70);
    root->left->right=new Node(40);
    root->right->left=new Node(60);
    root->right->right=new Node(80);

    cout<<"Inorder Traversal : ";
    inorderTra( root );

    cout<<"\n\nDeleting Node 50";
    root = delNode( root , 50);

    cout<<"\n\nInorder Traversal : ";
    inorderTra( root );

    
    Node* root2=new Node(50);
    root2->left=new Node(30);
    root2->right=new Node(70);
    root2->left->right=new Node(40);
    root2->right->left=new Node(60);
    root2->right->right=new Node(80);

    cout<<"\n\n\nInorder Traversal : ";
    inorderTra( root2 );

    cout<<"\n\nDeleting Node 70";
    root = delNode( root2 , 70);

    cout<<"\n\nInorder Traversal : ";
    inorderTra( root2 );
}