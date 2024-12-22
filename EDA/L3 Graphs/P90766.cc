#include <iostream>
#include <vector>

using namespace std;

int dfs(int i, int j, vector<vector<char>>& map,vector<vector<bool>>& visit){
    int num=0;
    if (not visit[i][j])
    {
        visit[i][j]=true;
        
        if(i>0 and map[i-1][j]!='X' ) num += dfs(i-1,j,map,visit);
        if(i<map.size()-1 and map[i+1][j]!='X' ) num += dfs(i+1,j,map,visit);
        if(j>0 and map[i][j-1]!='X' ) num += dfs(i,j-1,map,visit);
        if(j<map[i].size()-1 and map[i][j+1]!='X' ) num += dfs(i,j+1,map,visit);

        if(map[i][j]=='t') num++;
    }
    return num;
}

int main(int argc, char const *argv[])
{
    int a,b;
    cin >> a >> b;
    vector<vector<char>> map(a,vector<char>(b));
    vector<vector<bool>> visit(a,vector<bool>(b, false));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> map[i][j];
        }
    }
    
    cin >> a >> b;

    cout << dfs(a-1,b-1,map,visit) << endl;

}
