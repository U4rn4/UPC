#include <iostream>
#include <set>
#include <stack>
#include <sstream>
using namespace std;

int main(){
    int n;
    string ln;
    while (getline(cin,ln))
    {
        set<int> s;
        istringstream ss(ln);
        while (ss >> n) s.insert(n);
        
        stack<int> s2;
        set<int>::iterator it=s.begin();
        while (it!=s.end())
        {
            if(s2.empty()) s2.push(*it);
            else if((s2.top()%2==0 and *it%2!=0) or (s2.top()%2!=0 and *it%2==0)) s2.push(*it);
            it++;
        }
        cout << s2.size() << endl;
    }
    

}