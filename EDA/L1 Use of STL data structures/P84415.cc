#include <iostream>
#include <map>
using namespace std;

int main(){
    string com;
    map<string,int> m;
    while (cin>>com)
    {
        if (com=="store")
        {
            string name;
            cin >> name;
            m[name]++;
        }
        else if (com=="delete")
        {
            string name;
            cin >> name;
            if (m.find(name) != m.end())
            {
                m[name]--;
                if(m[name]==0) m.erase(name);
            }
        }
        else if (com=="minimum?")
        {
            if(m.empty()) cout << "indefinite minimum" << endl;
            else cout << "minimum: " << m.begin()->first << ", " << m.begin()->second << " time(s)" << endl;
        }
        else if (com=="maximum?")
        {
            if(m.empty()) cout << "indefinite maximum" << endl;
            else {
                map<string,int>::iterator it = m.end();
                it--;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }        
        
    }
    
}