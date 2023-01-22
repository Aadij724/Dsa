#include<iostream>
using namespace std;

class MyStack
{
    public:
        int *arr;
        int cap;
        int top;

    MyStack( int c )
    {
        cap=c;
        arr=new int[cap];
        top=-1;
    }

    void push( int x )
    {
        if( top == cap -1 )
        {
            cout<<"Stack is already full ( overflow )";
            return;
        }
        top++;
        arr[top]=x;
    }

    int pop()
    {
        if( top == -1 )
        {
            cout<<"Stack is already empty ( underflow )";
            return INT8_MAX;
        }
        int res=arr[top];
        top--;
        return res;
    }
    
    int peek()
    {
        if( top == -1 )
        {
            cout<<"Stack is empty";
            return INT8_MAX;
        }
        return arr[top];
    }

    int size()
    {
        return ( top + 1);
    }

    bool isEmpty()
    {
        return( top == -1 );
    }
};

int main()
{
    MyStack s(5);
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;

    return 0;
}