#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string str;
    stack<char> s;

    while (cin >> str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (s.empty() and (str[i]==')' or str[i]==']'))
            {
                s.push(str[i]);
            }
            else if (str[i]=='(' or str[i]=='[')
            {
                s.push(str[i]);
            }
            else if (str[i]==')' and s.top()=='(')
            {
                s.pop();
            }
            else if (str[i]==']' and s.top()=='[')
            {
                s.pop();
            }
            else if (str[i]==']' and s.top()=='(')
            {
                s.pop();
                --i;
            }
            else s.push(str[i]);
        }
        
        if(s.empty()) cout << endl;
        else
        {
            stack<char> s2;
            while (not s.empty())
            {
                s2.push(s.top());
                s.pop();
            }
            while (not s2.empty())
            {
                cout << s2.top();
                s2.pop();
            }
            cout << endl;
        }
        
    }
    
}