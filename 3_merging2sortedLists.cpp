// we will be merging two sorted linked lists
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};
void addmembers(node *&head, int value)
{
    if (head == NULL)
    {
        node *n = new node(value);
       head=n;
       return;
    }
    node *n = new node(value);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL"<<endl;
}
node* mergeSortedLists(node*a,node*b){
    if(a==NULL)
    return b;
    if(b==NULL)
    return a;
    node* c;
    if(a->data < b->data)
    {
     c=a;
    c->next=mergeSortedLists(a->next,b);
    } 
    else if(b->data < a->data)
    {
        c=b;
        c->next=mergeSortedLists(a,b->next);
    }
    return c;
}
node* midpointList(node*&head){
    node*fast=head;  //runner method(uses a slow pointer and fast pointer)
    node*slow=head;
    while( fast->next!=NULL && fast->next->next!=NULL)   //so if anyone of the condition is false then we exit the loop
    {
         fast= fast->next->next;
        slow=slow->next;
    }
   return slow;
}
int main()
{
    node *a = NULL;
    node *b = NULL;
    addmembers(a, 1);
    addmembers(a, 5);
    addmembers(a, 7);
    addmembers(a, 8);
    addmembers(b, 3);
    addmembers(b, 4);
    addmembers(b, 6);
    addmembers(b, 10);
    printList(a);
    printList(b);
    cout<<"Merging the sorted lists"<<endl;
    node* c = mergeSortedLists(a,b);
    printList(c);
    node* mid;
     mid= midpointList(c);
     cout<<endl<<mid->data;
    return 0;
}