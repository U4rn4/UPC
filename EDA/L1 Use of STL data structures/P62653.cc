// CASOS PUBLICOS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string w;
bool cmp(string s1, string s2){
    if (s1.length() == s2.length()) {
      string substr = w.substr(0, s1.length());
      if (s1 == substr) return false;
      else if (s2 == substr) return true;
      else if (s1 < s2) {
        if (s1 < substr and s2 > substr) return true;
        else return false;
      } else {
        if (s1 > substr and s2 < substr) return false;
        else return true;
      }
    } else return s1.length() > s2.length();
}


int main(){
    
    string com;
    while (cin >> w)
    {
        int tk =0;
        vector<string> v;
        while (cin >> com and com!="E")
        {
            if (com=="S")
            {
                string name;
                cin >> name;
                if(tk>0) {
                    tk--;
                    cout << name << endl;
                }
                else
                {
                    v.push_back(name);
                    sort(v.begin(),v.end(),cmp);
                }
                
            }
            else if (com=="T")
            {
                if (v.empty())
                {
                    tk++;
                }
                else{
                    cout << v.back() << endl;
                    v.pop_back();
                }
            }
            
        }
        cout << tk << " ticket(s) left" << endl;
        cout << v.size() << " supporter(s) with no ticket" << endl << endl;
    }
    
}