#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using VC = vector<char>;
using Map = vector<VC>;



int bfs(Map& mapa, int x, int y){
    queue<pair<int,int>> q;

    vector<vector<bool>> v(mapa.size(),vector<bool>(mapa[0].size(), false));
    vector<vector<int>> D(mapa.size(),vector<int>(mapa[0].size()));
    
    q.push(make_pair(y,x));
    v[y][x] = true;
    int maxd = 0;

    while (not q.empty())
    {
        int f = q.front().first;
        int c = q.front().second;

        q.pop();

        if (mapa[f][c]=='t' and D[f][c] > maxd)
        {
            maxd = D[f][c]; 
        }
        
        if (f>0 and mapa[f-1][c]!='X' and not v[f-1][c]){
            v[f-1][c]=true;
            q.push(make_pair(f-1,c));
            D[f-1][c] = D[f][c]+1;
        }
        if (c>0 and mapa[f][c-1]!='X' and not v[f][c-1]){
            v[f][c-1]=true;
            q.push(make_pair(f,c-1));
            D[f][c-1] = D[f][c]+1;
        }
        if (f<mapa.size()-1 and mapa[f+1][c]!='X' and not v[f+1][c]){
            v[f+1][c]=true;
            q.push(make_pair(f+1,c));
            D[f+1][c] = D[f][c]+1;
        }
        if (c<mapa[f].size()-1 and mapa[f][c+1]!='X' and not v[f][c+1]){
            v[f][c+1]=true;
            q.push(make_pair(f,c+1));
            D[f][c+1] = D[f][c]+1;
        }
    }
    return maxd;
}

int main(int argc, char const *argv[])
{
    int f,c;
    cin >> f >> c;
    Map mapa(f, VC(c));

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mapa[i][j];
        }
    }
    int x,y;
    cin >> y >> x;
    y--;
    x--;
    int dis = bfs(mapa,x,y);
    if (dis==0)
    {
        cout << "no es pot arribar a cap tresor" << endl;
    }
    else cout << "distancia maxima: " << dis << endl;
}
