#include <iostream>
#include <vector>

using namespace std;

using VVB = vector<vector<bool>>;
using VB = vector<bool>;

void bt(VVB& m,VB& f, VB& c, VB& d1, VB& d2, int ix){
    if (f.size()==ix)
    {
        for (int i = 0; i < m.size(); i++)
        {
            for (int j = 0; j < m.size(); j++)
            {
                if (m[i][j])
                {
                    cout << "Q";
                }
                else cout << ".";
            }
            cout << endl;
        }
        cout << endl;
    }
    else{
        
        for (int j = 0; j < c.size(); j++)
        {
            if ((not f[ix]) and (not c[j]) and (not d1[ix+j]) and (not d2[ix-j+c.size()]))
            {
                f[ix]=true;
                c[j]=true;
                d1[ix+j]=true;
                d2[ix-j+c.size()]=true;
                m[ix][j]=true;
                bt(m,f,c,d1,d2,ix+1);
                f[ix]=false;
                m[ix][j]=false;
                c[j]=false;
                d1[ix+j]=false;
                d2[ix-j+c.size()]=false;
            }
                
        }
            
        
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    VB f(n, false);
    VB c(n,false);
    VB d1(2*n-1, false);
    VB d2((2*n-1), false);
    VVB m(n,vector<bool>(n,false));
    bt(m,f,c,d1,d2,0);

    return 0;
}
