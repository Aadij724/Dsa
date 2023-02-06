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

void bottomView( Node* root )
{
    map<int, int> mp;
    if( root==NULL ) return;
    queue< pair<Node*, int> > q;
    q.push( {root, 0} );
    Node* curr;
    while( q.empty()==false )
    {
        auto p=q.front();
        curr=p.first;
        int hd=p.second;
        mp[hd]=curr->key;
        q.pop();
        //cout<<curr->key<<" ";

        if( curr->left != NULL)
            q.push( {curr->left, hd-1} );
        if( curr->right != NULL )
            q.push( {curr->right, hd+1} );
    }

    for( auto a: mp )
        cout<<a.second<<" ";
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(50);
    root->left->left=new Node(30);
    root->left->right=new Node(40);
    root->right->left=new Node(60);
    root->right->right=new Node(70);

    cout<<"Bottom View of Binary Tree : ";
    bottomView( root );

    cout<<"\n\n";

    Node* root2=new Node(10);
    root2->left=new Node(20);
    root2->left->left=new Node(40);
    root2->left->right=new Node(50);
    root2->right=new Node(30);

    cout<<"Bottom View of Binary Tree : ";
    bottomView( root2 );
}