#include<iostream>
using namespace std;

void swap( int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void selectionSort( int arr[], int n)
{
    int temp[n];
    int min_ind;
    for(int i=0; i<n; i++)
    {
        min_ind=0;
        for( int j=1; j<n; j++)
        {
            if( arr[j] < arr[min_ind] )
                min_ind=j;
        }
        temp[i]=arr[min_ind];
        arr[min_ind]= INT8_MAX;
    }

    for(int i=0; i<n ; i++ )
    {
        arr[i]=temp[i];
    }
}

int main()
{
    int n=8;
   int arr[n]={ 56, 1, 78, 23, 12, 98, 34, 67};
   cout<<"Before sort : ";
   for( int q=0; q<n; q++)
   {
    cout<<arr[q]<<" ";
   }

   selectionSort( arr, n );

   cout<<"\nAfter sort : ";
   for(int q=0; q<n; q++)
   {
    cout<<arr[q]<<" ";
   }

}