#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
    map<string,int> m1;
    map<int,set<string>> m2;
    string s;
    int num;
    while (cin >> s)
    {
        if (s=="NEWPERSON")
        {
            cin >> s >> num;
            m1[s]=num;
            m2[num].insert(s);
        }
        else if (s=="BIRTHDAY")
        {
            cin >> s;
            m2[m1[s]].erase(s);
            m1[s]++;
            m2[m1[s]].insert(s);
        }
        else if (s=="NUMBERWITHAGE")
        {
            cin >> num;
            cout << m2[num].size() << endl;
        }
        else{
            cin >> num;
            
            if (m2[num].empty())
            {
                cout << endl;
            }
            else {
                set<string>::const_iterator it=m2[num].begin();
                cout << *it;
                it++;
                while (it!=m2[num].end())
                {
                    cout << " " << *it;
                    ++it;
                }
                cout << endl;
            }
            
        }
        
        
        
    }
    
}