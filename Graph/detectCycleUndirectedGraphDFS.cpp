#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge( vector<int> adj[], int u, int v )
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool DFSRec( vector<int> adj[], int s, bool visited[], int parent )
{
    visited[s]=true;
    for( int u : adj[s] )
    {
        if( visited[u]==false )
            if( DFSRec(adj, u, visited, s)==true )
                return true;
        else if( u!=parent )
            return true;
    }
    return false;
}

bool DFS( vector<int> adj[], int v )
{
    bool visited[v];
    for( int i=0; i<v; i++ )
        visited[i]=false;
    for( int i=0; i<v; i++ )
    {
        if( visited[i]==false )
            if( DFSRec( adj, i, visited, -1 )==true )
                return true;
    }
}

int main()
{
    int v=6;
    vector<int> adj[v];
    addEdge( adj, 0, 1 );
    addEdge( adj, 1, 2 );
    addEdge( adj, 1, 3 );
    addEdge( adj, 2, 3 );
    addEdge( adj, 2, 4 );
    addEdge( adj, 4, 5 );
    
    cout<<"Cycle is present : "<<DFS( adj, v );

    int v2=5;
    vector<int> adj2[v2];
    addEdge(adj2, 0, 1 );
    addEdge( adj2, 1, 2 );
    addEdge( adj2, 2, 3 );
    addEdge( adj2, 3, 4 );
    
    cout<<"\n\nCycle is present : "<<DFS( adj2, v2 );
    
}