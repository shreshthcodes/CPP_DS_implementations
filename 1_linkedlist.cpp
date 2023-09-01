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
// Insert at head
void insertAtHead(node *&head, int value)
{
    if (head == NULL)
    {
        node *n = new node(value);
        head = n;
        return;
    }
    node *n = new node(value);
    n->next = head;
    head = n;
}
// To calulate the length of LL
int lengthLL(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
// Insert at tail
void insertInEnd(node *&head, int value)
{
    cout<<"inserted "<<value<<" at the tail"<<endl;
    if (head == NULL)
    {
        node *n = new node(value);
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *n = new node(value);
    temp->next = n;
    return;
}
// Insert in the middle
void insertInMiddle(node *&head, int value, int position)
{
    if (head == NULL || position == 0)
    {
        insertAtHead(head, value);
        return;
    }
    if (position > lengthLL(head))
    {
        insertInEnd(head, value);
        return;
    }
    node *temp = head;
    int track = 0;
    while (position != track)
    {
        temp = temp->next;
        track++;
    }
    node *n = new node(value);
    n->next = temp->next;
    temp->next = n;
    return;
}
// delete head
void deletehead(node *&head)
{
    cout << "head deleted" << endl;
    if (head == NULL)
        return;
    node *temp = head;
    temp = head->next;
    delete head;
    head = temp;
}
// delete tail
void deletetail(node *head)
{
    if (head == NULL)
        return;
    cout << "tail deleted" << endl;
    node *temp = head->next;
    while (temp->next != NULL)
    {
        temp = temp->next;
        head = head->next;
    }
    delete temp;
    head->next = NULL;
}
//deleting in between the list 
void deleteInBetween(node *&head, int pos)
{
    cout<<"deleting in the "<<pos<<" position"<<endl;
    if (head == NULL)
        return;
    if (pos >= lengthLL(head))
    {
        cout<<"position greater than the length of the List deleting the end node"<<endl;
        deletetail(head);
        return;
    }
    if(pos==1)
    {
        deletehead(head);
    }
    node*initial=head;
    node *temp = head->next;
    while (pos != 2)
    {
        initial = initial->next;
        temp = temp->next;
        pos--;
    }
    initial->next = temp->next;
    delete temp;

}
// Print ll
void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NUll" << endl;
}
//Reversing the linked list (iterative)
void reverseList(node* &head)
{
    cout<<"Reversing the linked list"<<endl;
node* prev=NULL;
node* current=NULL;
while(head!=NULL)
{
    current=head;
    head=head->next;
    current->next=prev;
    prev=current;
}
head=current;
}
//Reverse linked list using recurrsion
node * reverseListRecursion(node* head){
    if(head->next==NULL || head==NULL)  //base case(termination condition)
    return head;
    node * shead=reverseListRecursion(head->next);
    //given below will reverse the list in O(n^2) TC cause the while loop 
    // node* temp = shead;
    // while(temp->next!=NULL)
    // temp = temp->next;
    // temp->next=head;
    // head->next=NULL;
    //return shead;
    //given below is the more efficient approach because it will reverse in O(n) TC
    node* temp;
    temp=head->next;
    head->next=NULL;
    temp->next=head;
    return shead;
}
//midpoint of the list
// node* midpointList(node*head){
//     if(head==NULL || head->next==NULL)
//     return head;
//     node*fast=head->next;
//     node*slow=head;
//     while(fast!=NULL ||fast->next!=NULL)
//     {
//         fast=fast->next->next;
//         slow= slow->next;
//     }
//     return slow;
// }
//midpoint of the list
node* midpointList(node*head){
    if(head==NULL||head->next==NULL)
    return head;
    node*fast=head;  //runner method(uses a slow pointer and fast pointer)
    node*slow=head;
    while(fast->next!=NULL || fast->next->next!=NULL)
    {
        fast= fast->next->next;
        // cout<<"fast "<<fast->data<<endl;
        slow=slow->next;
        // cout<<"slow "<<slow->data<<endl;
    }
   return slow;
}
int main()
{
    node *head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    printList(head);
    insertInMiddle(head, 4, 1);
    insertInEnd(head, 5);
    insertInEnd(head, 6);
    printList(head);
    deletehead(head);
    printList(head);
    deletetail(head);
    printList(head);
    deleteInBetween(head,2);
    deleteInBetween(head,10);
    printList(head);
    insertInEnd(head, 4);
    insertInEnd(head, 5);
    insertInEnd(head, 6);
    reverseList(head);
    printList(head);
    cout<<"Reversing the linked list using recursion"<<endl;
    head=reverseListRecursion(head);
    printList(head);
    cout<<"Reversing the linked list using recursion"<<endl;
    head=reverseListRecursion(head);
    printList(head);
    // deletetail(head);
    node* mid;
    mid = midpointList(head);
    cout<<"The mid point of the list is "<<mid->data<<endl;
    return 0;
}