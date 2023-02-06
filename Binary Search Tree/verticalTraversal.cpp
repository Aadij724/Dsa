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


    
void vTraversal( Node* root )
{
    map<int, vector<int>> mp;

    if( root==NULL ) return;
    queue< pair<Node*, int> > q;
    q.push( {root, 0} );
    Node* curr;
    while( q.empty()==false )
    {
        auto p=q.front();
        curr=p.first;
        int hd=p.second;
        mp[hd].push_back( curr->key );
        q.pop();
        //cout<<curr->key<<" ";
        if( curr->left != NULL)
            q.push( {curr->left, hd-1} );
        if( curr->right != NULL )
            q.push( {curr->right, hd+1} );
    }

    for( auto a: mp)
    {
        for( auto b: a.second)
            cout<<b<<" ";
        cout<<"\n";
    }
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);

    cout<<"Vertical Traversal of Binary Tree : \n";
    vTraversal( root );

    cout<<"\n\n";

    Node* root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->left->left=new Node(4);
    root2->left->right=new Node(5);
    root2->right->left=new Node(6);
    root2->right->right=new Node(7);
    root2->right->right->left=new Node(8);
    root2->right->right->left->left=new Node(9);

    cout<<"Vertical Traversal of Binary Tree : \n";
    vTraversal( root2 );
}