#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct player
{
    int elo;
    bool online=true;
};

bool cmp(pair<int,string> p1, pair<int,string> p2){
    if (p1.first != p2.first)
    {
        return p1.first > p2.first;
    }
    else return p1.second < p2.second;
}

int main(){
    
    string com;
    map<string,player> m;
    vector<pair<int,string>> v;
    while (cin >> com)
    {
        if (com=="LOGIN")
        {
            string name;
            cin >> name;
            if (m.find(name)==m.end())
            {
                m[name].elo = 1200;
            }
            else
            {
                m[name].online = true;
            }
            
        }
        else if (com=="LOGOUT")
        {
            string name;
            cin >> name;
            if (m.find(name)!=m.end())
            {
                m[name].online = false;
            }
            
        }
        else if (com=="PLAY")
        {
            string p1,p2;
            cin >> p1 >> p2;
            if (m.find(p1)==m.end() or m.find(p2)==m.end() or m[p1].online==false or m[p2].online==false)
            {
                cout << "player(s) not connected" << endl;
            }
            else
            {
                if (m[p2].elo >= 1210)
                {
                    m[p2].elo -= 10;
                }
                m[p1].elo += 10;
            }
            
        }
        else if (com=="GET_ELO")
        {
            string name;
            cin >> name;
            if (m.find(name)!=m.end())
            {
                cout << name << " " << m[name].elo << endl;
            }
            
        }
        
    }
    
    cout << endl << "RANKING" << endl ;

    auto it = m.begin();
    
    while (it!=m.end())
    {
        v.push_back(make_pair(it->second.elo,it->first));
        
        it++; 
    }

    sort(v.begin(),v.end(),cmp);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].second << " " << v[i].first << endl;
    }
    
    
}