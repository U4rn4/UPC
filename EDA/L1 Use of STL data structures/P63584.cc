#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> VI; 
typedef vector<VI> VVI;


int k_esim(int k, const vector<vector<int> >& V){
    map <int, int> m;
    for (int i = 0; i < V.size(); i++) if(not V[i].empty()) m[V[i][0]] = i;
    
    pair<int,int> p;
    VI c(V.size(),1);
    while (k>0)
    {
        p.first = m.begin()->first;
        p.second = m.begin()->second;
        if (V[p.second].size() > c[p.second])
        {
            m[V[p.second][c[p.second]++]] = p.second;
        }
        m.erase(m.begin());
        k--;
    }
    

    return p.first;
    
}