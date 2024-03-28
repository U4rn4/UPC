#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string,int> m;
    map<int, int> m2;
    string instruct, name;
    int coins;
    while (cin >> instruct)
    {
        if (instruct=="NUMPEOPLE"){
            cin >> coins;
            cout << m2[coins] << endl;
        }
        else if (instruct == "ADD")
        {
            cin >> name >> coins;
            m[name] = coins;
            m2[coins]++;
        }
        else
        {
            cin >> name;
            --m2[m[name]];
            m.erase(name);
            
        }
    }
    
}