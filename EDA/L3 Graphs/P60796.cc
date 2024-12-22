#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<char>>& v, vector<vector<int>>& D, int& x, int& y){
    queue<int> q1;
    queue<int> q2;
    q1.push(x);
    q2.push(y);

    D[x][y]=0;

    while (not q1.empty())
    {
        x = q1.front();
        y=q2.front();
        q1.pop();
        q2.pop();

        if (v[x][y]=='t')
        {
            return true;
        }
        

        if (x<(v.size()-1) and v[x+1][y]!='X' and D[x+1][y]==-1)
        {
            q1.push(x+1);
            q2.push(y);
            D[x+1][y]=D[x][y]+1;
        }
        if (x>0 and v[x-1][y] != 'X' and D[x-1][y] == -1){
            q1.push(x-1);
            q2.push(y);
            D[x-1][y] = D[x][y] + 1;
        }    
        if (y<(v[x].size()-1) and v[x][y+1] != 'X' and D[x][y+1] == -1){
            q1.push(x);
            q2.push(y+1);
            D[x][y+1] = D[x][y] + 1;        
        }
        if (y > 0 and v[x][y-1] != 'X' and D[x][y-1] == -1){
            q1.push(x);
            q2.push(y-1);
            D[x][y-1] = D[x][y] + 1;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int a,b;
    cin >> a >> b;
    vector<vector<char>> v(a,vector<char>(b));

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> v[i][j];
        }
        
    }
    vector<vector<int>> D(a, vector<int>(b, -1));
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    bool found = bfs(v,D,x,y);
    if (found)
    {
        cout << "minimum distance: "  << D[x][y] << endl;
    }
    else cout << "no treasure can be reached" << endl;
    return 0;
}
