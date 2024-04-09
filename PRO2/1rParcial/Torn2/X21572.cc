#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string,int> m1;
    map<string,int> m2;
    string s;
    int num;
    while (cin >> s)
    {
        if (s=="TRANSACTION")
        {
            cin >> s;
            cin >> num;
            m1[s]+=num;
            if(m1[s]<0) m2[s]+=num;
            else if(m1[s] >= 0 and m2.find(s)!=m2.end()) m2.erase(s);
        }
        else if (s=="NUMBERINRED")
        {
            cout << m2.size() << endl;
        }
        else{
            if (not m2.empty())
            {
                auto it = m2.begin();
                cout << it->first;
                it++;
                while (it!=m2.end())
                {
                    cout << " " << it->first;
                    it++;
                }
                cout << endl;
            }
            else cout << endl;
            
            
        }
        
    }
    
}