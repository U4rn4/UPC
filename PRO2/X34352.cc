#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> m;
    string str;
    char ch;
    while (cin >> ch >> str)
    {
        if (ch == 'a')
        {
            m[str]++;
        }
        else
        {

            
            cout << m[str] << endl;

        }
    }
    
}
