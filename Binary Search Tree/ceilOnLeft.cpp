#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void printCeiling( int arr[], int n )
{
    cout<<-1<<" ";
    set<int> s;
    s.insert( arr[0] );

    for( int i=1; i<n; i++ )
    {
        auto it= s.upper_bound( arr[i] );
        if( it != s.end() )
            cout<< *it <<" ";
        else
            cout<<-1<<" ";
        s.insert( arr[i] );
    }
}

int main()
{
    int arr[] = { 2, 8, 30, 15, 25, 12 };
    printCeiling( arr, 6);

    cout<<"\n\n";
    int arr2[] = { 30, 20, 10 };
    printCeiling( arr2, 3 );
   
    cout<<"\n\n";
    int arr3[] = { 10, 20, 30 };
    printCeiling( arr3, 3 );

    cout<<"\n\n";
    int arr4[] = { 6, 18, 4, 5 };
    printCeiling( arr4, 4 );
}