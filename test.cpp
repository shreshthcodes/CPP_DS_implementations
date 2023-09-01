#include<bits/stdc++.h>
using namespace std;
int main()
{
map<int,int>m;
m[1]=1;
if(!m.count(1))
m[1]=9;

m[1]+=1;
cout<<m[1];
return 0;
}