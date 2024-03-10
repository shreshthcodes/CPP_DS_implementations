#include<bits/stdc++.h>
using namespace std;
class store{
map<int,int>mp;
public:
void insert(int val){
if(mp.count(val))
return;
mp[val]=val;
}
void remove(int val){
if(mp.count(val)) mp.erase(val);
else 
return;
}
int getRandom(){
if(mp.size()==0)
return 0;
else{
random_device rd; // obtain a random number from hardware
mt19937 gen(rd()); // seed the generator
uniform_int_distribution<> distr(0, mp.size());
return distr(gen);
}
}
void print(){
    for(auto i:mp){
        cout<<i.second<<" ";
    }
}
};
int main()
{
store*s=new store();
s->insert(5);
s->remove(5);
int n=s->getRandom();
cout<<n;
s->print();
return 0;
}