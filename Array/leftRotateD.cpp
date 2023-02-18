#include<iostream>
using namespace std;

// Method 1

/*
void leftRotateOne( int arr[], int n )
{
    int temp= arr[0];
    for( int i=0; i<n-1; i++ )
        arr[i]=arr[i+1];
    arr[n-1]=temp;
}

void leftRotateD( int arr[], int n, int d )
{
    for( int j=0; j<d; j++ )
        leftRotateOne( arr, n);
}
*/



// Method 3

void swap( int &a, int &b )
{
    int temp=a;
    a=b;
    b=temp;
}

void reverse( int arr[], int low, int high )
{
    while( low < high )
    {
        swap( arr[low], arr[high] );
        low++;
        high--;
    }
}

void leftRotate( int arr[], int n, int d )
{
    reverse( arr, 0, d-1 );
    reverse( arr, d, n-1 );
    reverse( arr, 0, n-1 );
}



int main()
{
    int n=5;
    int arr[n]={1,2,3,4,5};

    leftRotate( arr, n, 3);

    for( int i=0; i<n; i++ )
        cout<<arr[i]<<" ";
}