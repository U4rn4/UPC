#include <iostream>
#include <stack>
using namespace std;

int main()
{
    char a;
    bool b = true;
    int c = 0;
    stack<char> s; 

    while (cin >> a and a!='.' and b)
    {
        
        if ((a == ']' or a== ')') and s.empty()) b = false;
        else if(a=='(' or a=='[') s.push(a);
        else if (a == ')' and s.top()!='(') b=false;
        else if (a == ']' and s.top()!='[') b = false;
        else s.pop();
        c++;
    }
    if (not s.empty())
    {
        b=false;
    }
    
    
    if (b==true) cout << "Correcte" << endl;
    else cout << "Incorrecte " << c << endl;

}
