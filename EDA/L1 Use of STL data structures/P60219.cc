#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string s1, string s2){
    if (s1.length()!=s2.length()) return s1.length() < s2.length();
    else return s1 < s2;
    
}

void fin(set<string>& s, set<string>& s2){
    vector<string> v;
    auto it = s2.begin();
    while (it != s2.end())
    {
        v.push_back(*it);
        it++;
    }
    sort(v.begin(),v.end(),cmp);

    cout << "HAS:" << endl;
    it = s.begin();
    
    while (it!=s.end())
    {
        cout << *it << endl;
        it++;
    }
    cout << endl;

    cout << "HAD:" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    
}

int main(){
    set<string> s1;
    set<string> s2;
    int count=0;
    string str;
    while (cin >> str and str!="QUIT")
    {
        if (str=="END")
        {
            count++;
            cout << "GAME #" << count << endl ;
            fin(s1,s2);
            s1.clear();
            s2.clear();
            cout << endl;
        }
        else
        {
            if (s1.find(str)!=s1.end())
            {
                s2.insert(str);
                s1.erase(str);
                
            }
            else
            {
                s1.insert(str);
                s2.erase(str);
            }
            
        }
        
    }
    count++;
    cout << "GAME #" << count << endl ;
    fin(s1,s2);
}