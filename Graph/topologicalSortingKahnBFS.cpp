#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge( vector<int> adj[], int u, int v )
{
    adj[u].push_back( v );
}

void topologicalSortKahnBFS( vector<int> adj[], int v )
{
    int indegree[v];
    for( int j=0; j<v; j++ )
        indegree[j]=0;
    for( int i=0; i<v; i++ )
    {
        for( int u: adj[i] )
            indegree[u]++;
    }

    queue<int> q;
    for( int p=0; p<v; p++ )
    {
        if( indegree[p]==0 )
            q.push( p );
    }

    while( q.empty()==false )
    {
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        for( int a: adj[u] )
        {
            indegree[a]--;
            if( indegree[a]==0 )
                q.push(a);
        }
    }
    
}




int main()
{
    int v=5;
    vector<int> adj[v];
    int indegree[v];

    for( int i=0; i<v; i++ )
        indegree[i]=0;

    addEdge( adj, 0, 2);
    addEdge( adj, 2, 3);
    addEdge( adj, 0, 3);
    addEdge( adj, 1, 3);
    addEdge( adj, 1, 4);
    
    topologicalSortKahnBFS(adj, 5);
}