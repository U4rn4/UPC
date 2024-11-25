#include <iostream>
#include <map>
using namespace std;

int main(){
    int x,y,n;
    while (cin >>x>>y>>n)
    {
        int lsiz=0;
        map<int,int> s;
        s[n]=0;
        int i = 1;
        while (n <= 100000000 and s.size()>lsiz)
        {
            lsiz++;
            if (n%2==0)
            {
                n = n/2;
                n += x;
                if (s.find(n)==s.end())
                {
                    s[n]=i;
                }
                
            }
            else 
            {
                n = n*3;
                n += y;
                if (s.find(n)==s.end()) s[n]=i;
            }
            i++;
            
        }
        if(n > 100000000) cout << n << endl;
        else
        {
            cout << s.size() - s.find(n)->second << endl;
        }
        
    }
    
    
}