#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string,int> m;
    string name, com;
    while (cin >> name >> com )
    {
        if (com == "enters")
        {
            if (m.find(name)==m.end()) m[name]=0;
            else cout << name << " is already in the casino" << endl;
        }
        else if(com == "wins"){
            int num;
            cin >> num;
            if (m.find(name)!=m.end())
            {
                m[name] += num;
            }
            else cout << name << " is not in the casino" << endl;
            
        }
        else if (com == "leaves")
        {
            if (m.find(name)!=m.end()){
                cout << name << " has won " << m[name] << endl;
                m.erase(name);
            }
            else cout << name << " is not in the casino" << endl;
        }
        
    }
    
    cout << "----------" << endl;
    map<string,int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " is winning " << it->second << endl;
        it++;
    }
    

}