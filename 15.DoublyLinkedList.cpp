#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;
     
    Node(){
        data=0;
        prev=NULL;
        next=NULL;
    }
    Node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};
void insertAtEnd(Node* &head,int val)
{
    if(head=NULL)
    {
        Node*n = new Node(val);
        head=n;
        return;
    }
    Node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node*n = new Node(val);
    temp->next=n;
    n->prev=temp;
    return;
}
void printDLL(Node*head){
    Node*temp= head;
    while(temp!=NULL)
    {
        cout<<head->data<<"<->";
        head=head->next;
    }
}
int main()
{
    Node* head;
    insertAtEnd(head,1);
    insertAtEnd(head,2);
    insertAtEnd(head,3);
    printDLL(head);

return 0;
}