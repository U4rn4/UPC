#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    stack<char> st;
    string s;
    while (cin >>s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if ((not st.empty()) and (((s[i]-'a'+'A')==st.top()) or (((s[i]+'a'-'A')==st.top()))))
            {
                st.pop();
            }
            else st.push(s[i]);
        }
        stack<char> s2;
        while (not st.empty())
        {
            s2.push(st.top());
            st.pop();
        }
        while (not s2.empty())
        {
            cout << s2.top();
            s2.pop();
        }
        cout << endl;
    }
    
}