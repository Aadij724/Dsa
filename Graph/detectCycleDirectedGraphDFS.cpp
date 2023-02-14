#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge( vector<int> adj[], int u, int v )
{
    adj[u].push_back(v);
}

bool DFSRec( vector<int> adj[], int s, bool visited[], bool recSt[] )
{
    visited[s]=true;
    recSt[s]=true;
    for( int u: adj[s] )
    {
        if( visited[u]==false && DFSRec( adj, u, visited, recSt ) )
            return true;
        else if( recSt[u]==true )
            return true;
    }
    recSt[s]=false;
    return false;
}

bool DFS( vector<int> adj[], int v )
{
    bool visited[v];
    bool recSt[v];
    for( int i=0; i<v; i++ )
        visited[i]=false;
    for( int i=0; i<v; i++ )
        recSt[i]=false;

    for( int i=0; i<v; i++ )
    {
        if( visited[i]==false )
            if( DFSRec( adj, i, visited, recSt )==true )
                return true;
    }
    return false;
}


int main()
{
    int v=6;
    vector<int> adj[v];
    addEdge( adj, 0, 1);
    addEdge( adj, 2, 1);
    addEdge( adj, 2, 3);
    addEdge( adj, 3, 4);
    addEdge( adj, 4, 5);
    addEdge( adj, 5, 3);
    
    cout<<"Cycle Detected : "<<DFS( adj, v );
}