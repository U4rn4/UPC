#include<iostream>
#include<vector>

using namespace std;
using VVI = vector<vector<int>>;
using VB = vector<bool>;
using VI = vector<int>;

bool cyclic(const VVI& g, int v, VB& visited, VI& father){
  // similar dfs
  // returns true iff the connected component containing v contains a cycle
    if(visited[v]) return true;
    visited[v]=true;
    for (int i = 0; i < g[v].size(); i++)
    {
        if (father[g[v][i]]!=v)
        {
            father[v]=g[v][i];
            if(cyclic(g,g[v][i],visited, father)) return true;
        }
           
    }
    return false;
}

int count_trees(const VVI& g){
    // use the auxiliary function cyclic to count the number of trees
    VB visit(g.size());
    VI f(g.size(),-1);
    int count = 0;

    for (int i = 0; i < g.size(); i++)
    {
        if (not visit[i])
        {
            if(cyclic(g,i,visit, f)) return -1;
            else ++count;
        }
        
    }
    
    return count;
}

int main(){
    int n, m;
    while (cin >> n >> m){
        VVI g(n);
        for (int k = 0; k < m; ++k){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int n_trees = count_trees(g); // -1 if g is not a tree
        if (n_trees == -1 ) cout << "no" << endl;
        else                cout << n_trees << endl;
    }
}
