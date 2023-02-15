#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge( vector<int> adj[], int u, int v )
{
    adj[u].push_back(v);
}

bool detectCycle( vector<int> adj[], int v )
{
    int indegree[v];
    for( int i=0; i<v; i++ )
        indegree[i]=0;
    for( int j=0; j<v; j++ )
    {
        for( int u:adj[j] )
            indegree[u]++;
    }


    queue<int> q;
    for( int j=0; j<v; j++ )
    {
        if( indegree[j]==0 )
            q.push( j );
    }

    int count=0;

    while( q.empty()==false )
    {
        int u=q.front();
        q.pop();
        for( int w:adj[u] )
        {
            indegree[w]--;
            if( indegree[w]==0 )
                q.push(w);
        }
        count++;
    }

    return ( count!=v );
}

int main()
{
    int v=5;
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    cout<<"Cycle detected : "<< detectCycle( adj, v );
}