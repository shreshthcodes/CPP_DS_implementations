#include <iostream>
using namespace std;
int recursiveLinearSearch(int *arr,int size,int key){
    if(size==0)   //key not found termination condition
    return -1;
    
    if(arr[0]==key)
    return 0;
    int i = recursiveLinearSearch(arr+1,size-1,key);
    
    if(i==-1)    //for returning -1 for every recursive call
    return -1;
    
    return i+1; // for counting the position at which we have the key
    
}

int main()
{
    int arr[]={3,5,2,1,8,0};
    int size= 6;
    int i=recursiveLinearSearch(arr,6,1);
    cout<<i;
    return 0;
}
