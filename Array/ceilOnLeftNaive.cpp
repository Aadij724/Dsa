#include<iostream>
using namespace std;

void printCeiling( int arr[], int n )
{
    cout<<-1<<" ";
    for( int i=1; i<n; i++ )
    {
        int diff = INT8_MAX;
        for( int j=0; j<i; j++ )
            if( arr[j] >= arr[i] )
                diff = min( diff, arr[j] - arr[i] );
        if( diff==INT8_MAX )
            cout<<-1<<" ";
        else
            cout<< arr[i] + diff<<" ";
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