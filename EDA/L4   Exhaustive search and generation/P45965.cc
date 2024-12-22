#include <iostream>
#include <vector>
using namespace std;

void bt(int z, int o, vector<int>& v, int index, int za, int oa){
    if (index==v.size())
    {
        for (int i = 0; i < v.size()-1; i++)
        {
            cout << v[i] << " ";
        }
        cout << v[v.size()-1] << endl;
    }
    else
    {
        
        if(z>=za+1){
            za++;
            v[index]=0;
            bt(z,o,v,index+1,za,oa);
            za--;
            v[index]=-1;
        }

        if(o>=oa+1){
            oa++;
            v[index]=1;
            bt(z,o,v,index+1,za,oa);
            oa--;
            v[index]=-1;
        }
    
        
    }
    
}

int main(int argc, char const *argv[])
{
    int n,o;
    cin >> n >> o;
    vector<int> v(n,-1);
    bt(n-o,o,v,0,0,0);
}
