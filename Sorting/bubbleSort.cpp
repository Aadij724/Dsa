#include<iostream>
using namespace std;


void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void bubbleSort1( int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j< n-i-1 ; j++)
        {
            if( arr[j] > arr[j+1] )
            {
                swap( arr[j], arr[j+1] );
            }
        }
    }
}

int main()
{
    /*
    cout<<"Enter no. of elements in array : ";
    int n;
    cin>>n;

    int *ar=new int[n];
    cout<<"Enter array elements : ";
    for(int d=0; d<n; d++)
    {
        cin>>ar[d];
    }
    */
   int n=8;
   int arr[n]={ 56, 1, 78, 23, 12, 98, 34, 67};
   cout<<"Before sort : ";
   for( int q=0; q<n; q++)
   {
    cout<<arr[q]<<" ";
   }

   bubbleSort1( arr, n );

   cout<<"\nAfter sort : ";
   for(int q=0; q<n; q++)
   {
    cout<<arr[q]<<" ";
   }

}