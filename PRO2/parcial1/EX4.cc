#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        stack<char> s; 
        int c=0;
        for (int i = 0; i < str.length(); i++)
        {
            if ((str[i] == ']' or str[i]== ')') and s.empty()) c++;
            else if(str[i]=='(' or str[i]=='[') s.push(str[i]);
            else if (str[i] == ')' and s.top()!='(') {
                c++;
                s.pop();
            }
            else if (str[i] == ']' and s.top()!='[') {
                c++;
                s.pop();
            }
            else s.pop();
        }

        cout << c << endl;

    }
    
}