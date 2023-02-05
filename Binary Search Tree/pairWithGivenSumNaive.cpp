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

bool isPairSum( Node* root, int sum )
{
    vector<int> v;

    stack<Node* > s;
    Node* curr=root;
    while( curr!=NULL || s.empty()==false )
    {
        while( curr!=NULL )
        {
            s.push( curr );
            curr= curr->left;
        }
        curr=s.top();
        s.pop();
        //cout<<curr->key<<" ";
        v.push_back( curr->key );
        curr=curr->right;
    }

    int i=0, j= v.size() -1;
    while( i < j )
    {
        if( (v[i] + v[j]) > sum )
            j--;
        else if( (v[i] + v[j]) < sum )
            i++;
        else
            return true;
    }
    return false;
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(8);
    root->right=new Node(20);
    root->left->left=new Node(4);
    root->left->right=new Node(9);
    root->right->left=new Node(11);
    root->right->right=new Node(30);
    root->right->right->left=new Node(25);

    cout<<"Pair with sum 33 is present in BST : ";
    cout<<isPairSum( root, 33 );

    cout<<"\n\n";

    Node* root2=new Node(20);
    root2->left=new Node(8);
    root2->right=new Node(40);
    root2->right->left=new Node(35);

    cout<<"Pair with sum 49 is present in BST : ";
    cout<<isPairSum( root, 49 );
}