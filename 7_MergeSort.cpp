#include<bits/stdc++.h>
using namespace std;
void print(int a[]){
    for(int i=0;i<9;i++)
    cout<<a[i]<<" ";
}
void merge(int a[],int p,int mid,int q){
    int n1= mid-p+1;
    int n2= q-mid;
    int r[n1+1],l[n2+1];
    for(int i = 0 ;i<=n1;i++)
    r[i]=a[i];
    for(int i = 0 ; i<=n2;i++)
    l[i]=a[(mid+1)+i];
    r[n1+1]=INT_MAX;
    l[n2+1]=INT_MAX;
    int i = 0 , j = 0;
    for(int k=0;k<q;k++){
        if(r[i]>l[j])
        {
            a[k]=l[j];
            j++;
        }
        else{
            a[k]=r[i];
            i++;
        }
    }
}
void mergeSort(int a[],int p, int q){
    if(p<q){
        int mid= (p+q)/2;
        mergeSort(a,p,mid);
        mergeSort(a,mid+1,q);
        merge(a,p,mid,q);
    }
}
int main()
{
int a[]={3,43,7,0,1,56,6,8,2};
mergeSort(a,0,8);
print(a);
return 0;
}