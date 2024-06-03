#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    int n;
    string s;
    cin >> n;
    vector< queue<string> > v(n);
    getline(cin, s);
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        istringstream ss(s);
        while (ss >> s )
        {
            v[i].push(s);
        }
    }
    
    cout << "DEPARTS" << endl <<"-------" << endl;

    while (cin >> s)
    {
        if (s == "LEAVES")
        {
            cin >> n;
            if (n-1 < v.size() and (not v[n-1].empty()))
            {
                cout << v[n-1].front() << endl;
                v[n-1].pop();
            }
            
        }   
        else if (s == "ENTERS")
        {
            cin >> s;
            cin >> n;
            if (n-1 < v.size())
            {
                v[n-1].push(s);
            }
            
        }
        
    }
    
    cout << endl << "FINAL CONTENTS" << endl << "--------------" << endl ;

    n = v.size();

    for (int i = 0; i < n; i++)
    {
        cout << "queue " << i+1 << ":";

        while (not v[i].empty())
        {
            cout << ' ' << v[i].front();
            v[i].pop();
        }
        cout << endl;
    }
    
    
}