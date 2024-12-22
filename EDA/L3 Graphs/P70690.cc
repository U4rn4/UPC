#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<char>>& v, vector<vector<bool>>& b, int i, int j){
    if(v[i][j]=='t') return true;
    bool found = false;
    b[i][j]=true;
    if (i>0 and v[i-1][j] != 'X' and not b[i-1][j])
        found = found or dfs(v, b, i-1, j); // up
    if (j<(v[i].size()-1) and v[i][j+1] != 'X' and not b[i][j+1])
        found = found or dfs(v, b, i, j+1); // right
    if (i<(v.size()-1) and v[i+1][j] != 'X' and not b[i+1][j])
        found = found or dfs(v, b, i+1, j); // down
    if (j> 0 and v[i][j-1] != 'X' and not b[i][j-1])
        found = found or dfs(v, b, i, j-1); // left
    
    return found;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
        
    }
    int x,y;
    cin >> x >> y;
    vector<vector<bool>> b(n, vector<bool>(m, false));
    bool found = dfs(v, b, x-1, y-1);
    if (found)
    {
        cout << "yes" << endl;
    }
    else cout << "no" << endl;
    return 0;
}
