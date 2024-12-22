#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using VVP = vector<vector<pair<int,int>>>;

int dijk(VVP& vec, int i, int f){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push(make_pair(0,i));
    vector<int> dist(vec.size(),1000000000);
    dist[i]=0;

    while (not q.empty())
    {
        int v = q.top().second;
        int d = q.top().first;
        q.pop();

        if (d<=dist[v])
        {
            for(auto aux : vec[v]){
                if (aux.first + dist[v] < dist[aux.second] )
                {
                    dist[aux.second]=aux.first + dist[v];
                    q.push(make_pair(dist[aux.second],aux.second));
                }
                
            }
        }
        
    }
    return dist[f];    
}

int main(int argc, char const *argv[])
{
    int v,m;
    while (cin >> v >> m)
    {
        int x,y,z;
        VVP vec(v,vector<pair<int,int>>(0));

        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> z;
            vec[x].push_back(make_pair(z,y));
        }    
        int i,f;
        cin >> i >> f;
        int found = dijk(vec,i,f);
        if(found == 1000000000) cout << "no path from "<< i <<" to " << f << endl;
        else cout << found << endl;
    }
    
    return 0;
}
