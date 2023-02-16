#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge( vector<int> adj[], int u, int v )
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void shortestPath( vector<int> adj[], int v, int s )
{
    int dist[v];
    for( int i=0; i<v; i++ )
        dist[i]=INT8_MAX;

    dist[s]=0;
    queue<int> q;
    
    int visited[v];
    for( int j=0; j<v; j++ )
        visited[j]=false;
    
    q.push(s);
    visited[s]=true;

    while( q.empty()==false )
    {
        int u=q.front();
        q.pop();
        for( int p: adj[u] )
        {
            if( visited[p]==false )
            {
                dist[p]=dist[u] + 1;
                visited[p]=true;
                q.push(p);
            }
        }
    }

    for( int i=0; i<v; i++ )
        cout<<dist[i]<<" ";
}

int main()
{
    int v=4;
    vector<int> adj[v];

    addEdge( adj, 0, 2 );
    addEdge( adj, 0, 1 );
    addEdge( adj, 1, 2 );
    addEdge( adj, 1, 3 );
    addEdge( adj, 2, 3 );

    shortestPath( adj, v, 0 );
}