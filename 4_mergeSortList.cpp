#include<bits/stdc++.h>
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
/*
merge sort procedure
1. First we need a base function(or the sorting algorithm) that we will use to merge the two sorted lists
in a sorted fashion, we already did that earlier(merging2sortedLists.cpp).
2. Now we will write 'the recursive function' to divide the list into two part with a base case.

The recursive function
1. First is the base case
2. Midpoint algorithm, to divide the list about its midpoint into two lists to sort separately.
3. Then the recursive call statements that divide the list till we can't divide it further.
4. finally at the end we will call the sorting algorithm, which will begin sorting from the individual elements 
  and combining the results into a bigger list till we the list original size.
*/
node* midpointList(node*head)
{
    node*fast=head;
    node*slow=head;
    while(fast->next==NULL && fast->next->next==NULL){
        fast= fast->next->next;
        slow = slow->next;
    }
    return slow;
}
// The merge sort procedure
node* merge(node*a, node*b){
    //1.base case
    if(a==NULL)
    return b;
    if(b==NULL)
    return a;

    //2. the sorting algorithm
    node* merged=NULL;
    if(a->data < b->data)
    {
        merged=a;
        merged->next=merge(a->next,b);
    }
    else if(b->data < a->data)
    {
        merged=b;
        merged->next=merge(a,b->next);
    }
    else if(a->data = b->data)
    {
        merged=a;
        merged->next=merge(a->next,b);
    }
    return merged;
}
//The recursive function
node* mergeSort(node* head){
    //base case
    if(head==NULL|| head->next==NULL){
        return head;
    }
     //break the list for merge sort
     node*mid=midpointList(head);
     node* a = head;
     node* b = mid->next;
     mid->next=NULL;

     //recursive calls
     a = mergeSort(a);
     b = mergeSort(b);

     //solving case
     node*c;
     c = merge(a,b);
     return c;

}
int main()
{   node*head=NULL;
    addmembers(head, 1);
    addmembers(head, 5);
    addmembers(head, 7);
    addmembers(head, 10);
    addmembers(head, 11);
    addmembers(head, 4);
    addmembers(head, 2);
    addmembers(head, 0);
    node * ans= mergeSort(head);
    printList(ans);
    return 0;
}