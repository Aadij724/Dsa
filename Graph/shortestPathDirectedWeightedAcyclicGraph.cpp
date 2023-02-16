#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge( vector< pair<int,int> > adj[], int u, int v, int weight )
{
    adj[u].push_back( make_pair(v,weight));
}


int* topologicalSortKahnBFS( vector< pair<int,int> > adj[], int v )
{
    int topSorArr[v];
    int c=0;

    int indegree[v];
    for( int j=0; j<v; j++ )
        indegree[j]=0;
    for( int i=0; i<v; i++ )
    {
        for( pair<int,int> u: adj[i] )
            indegree[u.first]++;
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

        topSorArr[c]=u;
        c++;

        q.pop();
        for( pair<int,int> a: adj[u] )
        {
            indegree[a.first]--;
            if( indegree[a.first]==0 )
                q.push(a.first);
        }
    }
    return topSorArr;
}


void shortestPath( vector< pair<int,int> > adj[], int s, int v )
{
    int dist[v];
    for( int i=0; i<v; i++ )
        dist[i]=INT8_MAX;
    
    dist[s]=0;
    int* topSorArr= topologicalSortKahnBFS( adj, v);

    for( int i=0; i<v; i++ )
    {
        for( pair<int,int> p: adj[i] )
        {
            if( dist[p.second] > (dist[i] + p.second) )
                dist[p.second]=dist[i]+ p.second;
        }
    }

    for( int i=0; i<v; i++)
        cout<<dist[i]<<" ";
}

int main()
{
    int v=6;
    vector<pair<int,int>> adj[v];

    addEdge( adj, 0, 1 , 2);
    addEdge( adj, 0, 4 , 1);
    addEdge( adj, 1, 2 , 3);
    addEdge( adj, 4, 2 , 2);
    addEdge( adj, 2, 3 , 6);
    addEdge( adj, 4, 5 , 4);
    addEdge( adj, 5, 3 , 1);
    
    shortestPath( adj, 0, 6 );
}