#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<vector<int>> VVI;

bool dfs(VVI& g, int v, VI& color){
    
    if (color[v]==-1)
    {
        bool c0=true, c1=true;
        for (int i : g[v])
        {
            if(color[i]==0) c0=false;
            if(color[i]==1) c1 = false;

        }
        if(c0) color[v]=0;
        else if(c1) color[v]=1;
        else return false;

        for (int i : g[v])
        {
            if(not dfs(g,i,color)) return false;
        }
        
    }
    return true;
}

bool coloreable(VVI& g){
    VI color(g.size(),-1);
    for (int i = 0; i < g.size(); i++)
    {
        if(color[i]==-1){
            if (not dfs(g, i, color)) return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int n,m;
    int a,b;
    while (cin >> n >> m)
    {
        VVI g(n);
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        if(coloreable(g)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    
}
