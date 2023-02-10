#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void addEdge( vector<int> adj[], int u, int v )
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void BFS( vector<int> adj[], int v, int s )
{
    bool visited[v];
    for( int i=0; i<v; i++ )
        visited[i]=false;
    queue<int> q;
    visited[s]=true;
    q.push(s);
    while( q.empty()==false )
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for( int v1: adj[u] )
        {
            if( visited[v1]==false )
            {
                visited[v1]=true;
                q.push(v1);
            }
        }
    }
}



int main()
{
    int v=7;
    vector<int> adj[v];
    addEdge( adj, 0, 1);
    addEdge( adj, 0, 2);
    addEdge( adj, 1, 2);
    addEdge( adj, 1, 3);
    addEdge( adj, 2, 3);
    addEdge( adj, 2, 4);
    addEdge( adj, 3, 4);
    
    cout<<"Breadth First Search Traversal : ";
    BFS( adj, v, 0);
}