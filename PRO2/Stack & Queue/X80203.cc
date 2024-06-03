#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int size;
    string s;
    stack<int> ch;

    while (cin >> s)
    {
        size = s.length();
        
        int a = 1;

        for (int i = 0; i < size; i++)
        {
            

            if (s[i] == '(')
            {
                cout << '(' << a;
                ch.push(a);
                ++a;
            }
            else if (s[i] == ')')
            {
                cout << ')' << ch.top();
                ch.pop();
                
            }
        }
        
        cout << endl;
    }
    

}