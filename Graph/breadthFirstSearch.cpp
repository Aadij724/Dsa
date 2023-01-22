#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge( vector<int> adj[], int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void printGraph( vector<int> adj[], int v)
{
    for( int i=0; i<v; i++)
    {
        for( int x: adj[i] )
            cout<<x<<" ";
        cout<<"\n";
    }
}


void BFS( vector<int> adj[], int v, int s)
{
    bool visited[v+1];
    for( int i=0; i<v; i++)
        visited[i]=false;

    queue<int> q;
    visited[s]=true;
    q.push(s);

    while( q.empty()==false )
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for( int v:adj[u] )
        {
            if( visited[v]==false )
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}

int main()
{
    int v=4;
    vector<int> adj[v];
    addEdge( adj, 0, 1);
    addEdge( adj,0 , 2);
    addEdge( adj, 1, 2);
    addEdge( adj, 1, 3);

    printGraph( adj, v);

    cout<<"\nBreadth First Search : ";
    BFS(adj, v, 0);
    return 0;
}