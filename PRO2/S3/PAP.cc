#include <iostream>
#include <stack>
using namespace std;

bool pal(stack<int> &s, int &b){
    int c;
    for (int i = 0; i < b; i++)
    {
        cin >> c; 
        if (c != s.top()) return false;
        s.pop();
    }
    return true;
}

int main()
{
    int a,b,c;
    stack<int> s;
    cin >> a;
    b = a/2;
    for (int i = 0; i < b; i++)
    {
        cin >> c;
        s.push(c);
    }
    if (a%2 == 1) cin >> c;
    if(pal(s,b)) cout << "SI" << endl;
    else cout << "NO" << endl;

}
