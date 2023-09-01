// #include <iostream>
// #include <map>
// #include <string>
// #include <math.h>
// #include<time.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> m;
    srand(time(0));
    // insertion

    // 1st method
    m.insert(make_pair("mango", 25));

    // 2nd method
    pair<string, int> p;
    p.first = "apple";
    p.second = 90;
    m.insert(p);

    // 3rd method
    m["orange"] = 70;

    // searching
    string s;
    cout << "Enter the fruit's name you want to find " << endl;
    cin >> s;

    // 1st method (using find(): this function returns an iterator to the key value pair)
    auto it = m.find(s);
    if (it != m.end())
        cout << "price of " << it->first << " is " << it->second << endl;
    else
    {
        cout << "no fruit found with this name \n";
        cout<<"Creating an entry for "<<s<<"..."<<endl;
        m[s] = rand() % 100;
    }

    // 2nd method (using count(): this method returns 1 if the key is present and 0 if not present)
    if (m.count(s))
        cout << "price of " << s << " is " << m[s] << endl;
    else
        cout << "No fruit with this name";

    // updation
    m[s] = 100;
    cout<<"price of "<<s<<" updated to "<<m[s]<<endl;
    // deletion
    m.erase(s);
    cout<<"deleting the entry for "<<s<<"..."<<endl;
     
    // Normal looping
      for(auto it = m.begin();it!=m.end();it++)
        cout << "price of " << it->first << " is " << it->second << endl;



    // looping using for each
    for (auto p : m)
        cout << "price of " << p.first << " is " << p.second << endl;

    return 0;
}