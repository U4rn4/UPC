#include <iostream>
#include <stack>
#include <string>
#include <list>
using namespace std;

int main()
{
    string s;
    while (cin >> s and s!="stp")
    {
        bool b=true;
        stack<char> pila;
        list<int> l;
        int i = 0;
        while (b==true and (i < s.length()))
        {
            if (s[i] == '(' or s[i]=='[')
            {
                pila.push(s[i]);
                l.push_back(i);
            }
            else if ((s[i]==']' or s[i]==')') and pila.empty())
            {
                b = false;
                l.push_back(i);
            }
            else if ((s[i]==')' and pila.top()!='(' ) or (s[i]==']' and pila.top()!='['))
            {
                b=false;
            }
            else
            {
                pila.pop();
                l.pop_back();
            }
            
            i++;
        }
        if(l.empty()) cout << i << endl;
        else cout << l.front() << endl;
    }
}