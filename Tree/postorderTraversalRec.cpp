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

void postorderTraversalRec(Node* head)
{
    if( head!=NULL )
    {
        postorderTraversalRec( head->left );
        postorderTraversalRec( head->right );
        cout<<head->key<<" ";
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

    cout<<"Postorder Traversal : ";
    postorderTraversalRec(head);

    Node* head2=new Node(1);
    head2->left=new Node(2);
    head2->right=new Node(2);
    head2->left->left=new Node(3);
    head2->left->right=new Node(4);
    head2->right->left=new Node(4);
    head2->right->right=new Node(3);

    cout<<"\n\nPostorder Traversal : ";
    postorderTraversalRec(head2);
    
}