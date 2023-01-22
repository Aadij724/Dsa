#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

    Node( int x)
    {
        data=x;
        next=NULL;
    }
};

Node* createLinkedList()
{
    Node* head=new Node(17);
    head->next=new Node(15);
    head->next->next=new Node(8);
    head->next->next->next=new Node(12);
    head->next->next->next->next=new Node(10);
    head->next->next->next->next->next=new Node(5);
    head->next->next->next->next->next->next=new Node(4);

    return head;
}

void traversal( Node* head)
{
    Node* curr=head;
    while( curr!=NULL )
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}


Node* segregateEvenOddNaive( Node* head )
{
    Node* curr=head;
    while( curr->next != NULL )
    {
        curr=curr->next;
    }

    Node* temp=head->next;
    Node* prev=head;
    Node* temp2=NULL;
    Node* temp3=NULL;

    while( (head->data % 2) != 0)
    {
        temp2=new Node(head->data);
        curr->next=temp2;
        head=head->next;
        delete prev;
        prev=head;
    }

    
    while( temp!=curr->next )
    {
        if( (temp->data % 2) != 0 )
        {
            prev->next=temp->next;
            temp2=new Node(temp->data);
            curr->next=temp2;
            temp3=temp;
            temp=temp->next;
            delete temp3;
            continue;
        }
        prev=temp;
        temp=temp->next;
    }
    
    return head;
}

int main()
{
    Node* head=createLinkedList();

    cout<<"Before segregation : ";
    traversal(head);

    
    head=segregateEvenOddNaive(head);

    cout<<"\n\nAfter segregation : ";
    traversal(head);

    return 0;
}