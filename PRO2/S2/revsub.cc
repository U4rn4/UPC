#include <iostream>
#include <string>

using namespace std;

// Pre: 0 <= i <= j < s.size()
// Post: el substring s[i..j] s'ha revessat. La resta de s no ha canviat.
void reverseSubstring(string &s, int i, int j){
    if (i < j)
    {
        int a = s[i];
        s[i] = s[j];
        s[j] = a;
        reverseSubstring(s, i+1, j-1);
    }
    
}


int main()
{
    int i, j;
    string s;

    while (cin >> s >> i >> j)
    {
        reverseSubstring(s, i, j);
        cout << s << endl;
    }
    
}
