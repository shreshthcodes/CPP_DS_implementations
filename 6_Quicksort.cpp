#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int p,int q) //This will be our pivot generating function the we will use to sort about pivot
{
    int x = a[p];
    int i = p;
    int j =i+1;
    while(j<=q)
    // array = {3,43,7,0,1,56,6,8,2};
    {
        if(a[j]<x)
        {
            i++;
            swap(a[j],a[i]);
        }
        j++;
    }
    swap(a[p],a[i]);
    return i;
}
void quickSort(int a[],int p, int q){
    if(p<q)
    {int m = partition(a,p,q);
    quickSort(a,p,m-1);
    quickSort(a,m+1,q);}
}
void print(int a[]){
    for(int i=0;i<9;i++)
    cout<<a[i]<<" ";
}
int main()
{
int a[]={3,43,7,0,1,56,6,8,2};
quickSort(a,0,8);
print(a);
return 0;
}