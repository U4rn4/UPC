#include <iostream>
#include <stack>
using namespace std;

int main()
{
    char a;
    bool b = true;
    int size;
    stack<char> s;

    cin >> a;
    s.push(a);
    while (a != '.' and b == true)
    {
        cin >> a;
        if ((s.top() == '(' or s.top() == '[') and a == '.' ) b = false
        {
            b = false;
            size = s.size();
        }
        else if (s.top() == '(' and a == ']' )
        {
            b = false;
            size = s.size();
        }
        else if (s.top() == '[' and a == ')' )
        {
            b = false;
            size = s.size();
        }
        s.push(a);
    }
    
    if (b==true) cout << "Correcte" << endl;
    else cout << "Incorrecte " << s << endl
    

}
