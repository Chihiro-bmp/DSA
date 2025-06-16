#include<bits/stdc++.h>
using namespace std;

class Node
{
private:
    /* data */
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        prev=next=NULL;
    }
    ~Node();
};

Node* DLL(int arr[], int index,int size,Node* back){

    if(index==size) return NULL;

    Node* temp=new Node(arr[index]);
    temp->prev=back;

    temp->next=DLL(arr, index+1, size, temp);
    return temp;
}
int main()
{

     int pos;

    cin>>pos;

    Node* head=nullptr;

    int arr[]={1,2,3,4,5};

    head=DLL(arr,0,5,NULL);


    if(pos==0){
        if(head==NULL){
            head=new Node(5);
        }else{
            Node* temp=new Node(5);

            temp->next=head;
            head->prev=temp;
            head=temp;
        }
    }else{

    Node* curr=head;

    while(--pos){
        curr=curr->next;
    }

    if(curr->next==NULL){

        Node* temp=new Node(5);
        curr->next=temp;
        temp->prev=curr;
    }else{
        Node* temp=new Node(5);

        temp->next=curr->next;
        temp->prev=curr;
        curr->next=temp;
        temp->next->prev=temp;
    }

}
    Node* temp=head;

    while(temp){

        cout<<temp->data<<" ";
        temp=temp->next;
    }

   
}
