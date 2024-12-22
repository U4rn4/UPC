// Topological sort
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using graph = vector<vector<int>>;
using VI = vector<int>;

VI compute_ordering(const graph& g, VI& indegree){
   // suggestion: use a priority_queue
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < g.size(); i++)
    {
        if(indegree[i]==0) q.push(i);
    }

    VI ord;

    while (not q.empty())
    {
        int v = q.top();
        q.pop();

        if(indegree[v]==0){
            ord.push_back(v);
            for (int i : g[v])
            {
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }

    }
    return ord;
}

void write(const VI& v){
    cout << v[0];
    for (size_t i = 1; i < v.size(); ++i)
        cout  << ' ' << v[i];
    cout << endl;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        graph g(n);
        VI indegree(n, 0);
        for (int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            ++indegree[v];//why could be useful to remember the in-degree of vertices?
        }
    VI ord = compute_ordering(g,indegree);
    write(ord);
    }
}
