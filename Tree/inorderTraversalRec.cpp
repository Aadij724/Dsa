#include<iostream>
using namespace std;

class Node
{
    public:
        int key;
        Node *left;
        Node *right;

    Node(int x)
    {
        key=x;
        left=NULL;
        right=NULL;
    }
};

void inorderTraversalRec(Node* head)
{
    if( head!=NULL )
    {
        inorderTraversalRec( head->left );
        cout<<head->key<<" ";
        inorderTraversalRec( head->right );
    }
}

int main()
{
    Node* head=new Node(38);
    head->left=new Node(14);
    head->right=new Node(56);
    head->left->left=new Node(8);
    head->left->right=new Node(23);
    head->left->right->left=new Node(18);
    head->right->left=new Node(45);
    head->right->right=new Node(82);
    head->right->right->left=new Node(70);

    cout<<"Inorder Traversal : ";
    inorderTraversalRec(head);
    
}