#include <bits/stdc++.h>
#include <string>
using namespace std;
class student
{
public:
    string firstname;
    string lastname;
    int rollno;
    student(string first, string last, int roll)
    {
        firstname = first;
        lastname = last;
        rollno = roll;
    }
    bool operator==(const student &s) const{
        return rollno == s.rollno ? true : false;
    }
};
class hashfunction
{    public:
    size_t operator()(const student &s) const
    {
        return (s.firstname.length() + s.lastname.length());
    }
};
 int main()
{
    unordered_map<student, int, hashfunction> m;
    student s1("rahul", "sharma", 34);
    student s2("vihan", "chauhan", 43);
    student s3("rahul", "sharma", 33);
    student s4("vihan", "chauhan", 44);

    m[s1] = 34;
    m[s2] = 43;
    m[s3] = 33;
    m[s4] = 44;
    auto it = m.find(s3);
    cout<<it->first<<" "<<it->second<<endl
    for (auto p : m)
    {
        cout << p.first.firstname << " " << p.first.lastname << " " << p.second << endl;
    }
    return 0;
}