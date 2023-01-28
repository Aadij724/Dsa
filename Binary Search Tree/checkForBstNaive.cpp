#include<iostream>
#include<bits/stdc++.h>
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

int getMax( Node* root )
{
    if( root==NULL )
        return INT8_MIN;
    else
        return max( root->key, max( getMax(root->left), getMax(root->right) ) );
}

int getMin( Node* root )
{
    if( root==NULL )
        return INT8_MAX;
    else
        return min( root->key, min( getMin(root->left), getMin(root->right) ) );
}

bool isBstNaive( Node* root )
{
    stack<Node*> st;
    Node* curr=root;
    while( curr!=NULL || st.empty()==false )
    {
        while( curr!=NULL )
        {
            st.push( curr );
            curr = curr->left;
        }
        curr=st.top();
        st.pop();

        int maxi=getMax( curr->left );
        int mini=getMin( curr->right );
        if( curr->key < maxi || curr->key > mini )
            return false;

        curr = curr->right;
    }
    return true;
}

int main()
{
    Node* root=new Node(20);
    root->left=new Node(8);
    root->right=new Node(30);
    root->right->left=new Node(18);
    root->right->right=new Node(35);

    cout<<"Tree is BST : ";
    cout<<isBstNaive( root );

    Node* root2=new Node(80);
    root2->left=new Node(70);
    root2->right=new Node(90);
    root2->left->left=new Node(60);
    root2->left->right=new Node(75);
    root2->right->left=new Node(85);
    root2->right->right=new Node(100);

    cout<<"\n\nTree is BST : ";
    cout<<isBstNaive( root2 );
}