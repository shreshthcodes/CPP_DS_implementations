#include<bits/stdc++.h>
using namespace std;
int main()
{
unordered_map<string,vector<string>>phonebook;

phonebook["shreshth"].push_back("78383483943");
phonebook["ram"].push_back("20873087483");
phonebook["shreshth"].push_back("89798374893");
phonebook["ram"].push_back("0990808093343");
phonebook["shaleen"].push_back("789374893784");
for(auto p:phonebook){
    cout<<"Numbers of "<<p.first<<" are : \n";
    for(auto it = p.second.begin();it!=p.second.end();it++)
    cout<<*it<<endl;
    cout<<endl;
}
  
  cout<<"Enter the name you want to find in the phone book ";
  string s;
  cin>>s;
  if(phonebook.count(s))
  {
    cout<<"The numbers of "<<s<<" are "<<endl;
    for(string nums:phonebook[s]){
        cout<<nums<<endl;
    }
  }
  else{
    cout<<"No numbers for found the the search"<<" '"<<s<<"' "<<endl;
  }

return 0;
}