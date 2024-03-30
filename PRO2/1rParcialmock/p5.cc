#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(){
    string s, a;
    
    map<string,set<string>> m;
    map<string,set<string>> m2;
    while (cin >> s)
    {
        
        if (s=="ENROLL")
        {
            cin >> s >> a;
            m[s].insert(a);
            m2[a].insert(s);
        }
        else if (s=="QUIT")
        {
            cin >> s >> a;
            m[s].erase(a);
            m2[a].erase(s);
        }
        else if (s=="SUBJECTSOFSTUDENT")
        {
            cin >> s;
            if (m[s].empty())
            {
                cout << endl;
            }
            else{
                
                set<string>::iterator it = m[s].begin();
                cout << *it;
                ++it;
                while (it!=m[s].end())
                {
                    cout << ' ' << *it;
                    ++it;
                }
                cout << endl;
            }
            
        }
        else{
            cin >> a;
            if (m2[a].empty())
            {
                cout << endl;
            }
            else {
                set<string>::iterator it;
                it = m2[a].begin();
                cout << *it ;
                ++it;
                while (it!=m2[a].end())
                {
                    cout << ' ' << *it;
                    ++it;
                }
                cout << endl;
            }
            
        }
        
    }
}