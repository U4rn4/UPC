#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string,int> m;
    string st;
    while (cin >> st)
    {
        if (st=="a")
        {
            cin >> st;
            m[st]++;
        }
        else if (st=="e")
        {
            cin >> st;
            if(m[st]!=0) m[st]--;
        }
        else{
            cin >> st;
            cout << m[st] << endl;
        }
        
        
    }
    
}