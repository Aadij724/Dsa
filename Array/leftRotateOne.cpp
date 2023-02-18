#include<iostream>
using namespace std;

void leftRotate( int arr[], int n )
{
    int temp= arr[n-1];
    for( int i=n-2; i>=0; i-- )
        arr[i+1]=arr[i];
    arr[0]=temp;
}

int main()
{
    int n=5;
    int arr[n]={1,2,3,4,5};

    leftRotate( arr, n );

    for( int i=0; i<n; i++ )
        cout<<arr[i]<<" ";
}