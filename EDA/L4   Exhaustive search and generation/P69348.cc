#include <iostream>
#include <vector>

using namespace std;

void bt(vector<int>& v, vector<bool>& b, int index){
    if (index==v.size())
    {
        cout << "(" ;
        for (int i = 0; i < v.size()-1; i++)
        {
            cout << v[i]+1 << ",";
        }
        cout << v[v.size()-1]+1 << ")" << endl;
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            if(not b[i]){
                b[i] = true;
                v[index]=i;
                bt(v,b,index+1);
                b[i]=false;
                v[index]=-1;
            }
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> v(n,-1);
    vector<bool> b(n, false);

    bt(v,b,0);

    return 0;
}
