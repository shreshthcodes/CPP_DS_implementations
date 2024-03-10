#include<bits/stdc++.h>
using namespace std;
int powFunct(int x, int y){
    //we'll be using recursion here
    //base 
    if(y==1)
    return x;

    //hypothesis 
    int res = powFunct(x,y/2);

    //induction
    res = res*res;

    if(y%2==1)
    res*=x;
    return res;
}
int main()
{
    int n,m;
    cout<<"Enter the number ";
    cin>>n;
    cout<<"Enter it power ";
    cin>>m;
cout<<"Ans: "<<powFunct(n,m);
return 0;
}