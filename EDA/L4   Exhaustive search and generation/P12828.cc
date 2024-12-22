#include <iostream>
#include <vector>

using namespace std;

void backtrack(int n, vector<int>& v, int i){

    if (i == v.size())
    {
        for (int j = 0; j < n-1; j++)
        {
            cout << v[j] << " ";
        }
        cout << v[n-1] << endl;
        
    }
    else{
        for (int j = 0; j < 2; j++)
        {
            v[i]=j;
            backtrack(n,v,i+1);
            v[i]=-1;
        }
    }

}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> v(n,-1);
    backtrack(n,v,0);
}
