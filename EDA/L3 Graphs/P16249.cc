#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

using VS = vector<string>;
using VVS = map<string,VS>;
using P = map<string,int>;

string topo(VVS& mapa, P& pred){
    priority_queue<string, vector<string>, greater<string>> q;
    map<string,VS>::iterator it=mapa.begin();
    int len=0;
    while (it!=mapa.end())
    {
        len += (*it).first.length();
        if(pred[(*it).first]==0) q.push((*it).first);
        it++;
    }
    string end;
    while (not q.empty())
    {
        string name = q.top();
        q.pop();
        
        end.append(name);

        
        for (string aux : mapa[name])
        {
            --pred[aux];
            if(pred[aux]==0) q.push(aux);
        }
        
    }
    if(not end.empty() and end.length()==len) return end;
    else return "NO VALID ORDERING";
}

int main(int argc, char const *argv[])
{
    int n, m;
    while (cin >> n)
    {
                
        VVS mapa;
        P pred;

        for (int i = 0; i < n; i++)
        {
            string task;
            cin >> task;
            mapa.insert(make_pair(task,VS(0)));
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            string prim, second;
            cin >> prim >> second;
            mapa[prim].push_back(second);
            pred[second]++;
        }
        
        cout << topo(mapa, pred) << endl;
        
    }

}
