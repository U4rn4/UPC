#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
bool applyOneRule(vector<char> &v, char follow)
{
    int n = v.size();
    if (v[n-1] == 'v' and (follow != '=')) {
        v[n-1] = 'E';
        return true;
    } else if(v[n-1] == 'n'){
        v[n-1] = 'E';
        return true;
        
    } else if (n >= 3 and v[n-3] == '(' and v[n-2] == 'E' and v[n-1] == ')' and (n == 3 or (v[n-4] != 'i' and v[n-4] != 'w'))) {
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.push_back('E');
        return true;

    } else if(n >= 3 and v[n-3] == 'E' and v[n-2] == '*' and v[n-1] == 'E'){
        v.pop_back();
        v.pop_back();
        return true;

    } else if(n >= 3 and v[n-3] == 'E' and v[n-2] == '+' and v[n-1] == 'E' and follow != '*'){
        v.pop_back();
        v.pop_back();
        return true;

    } else if(n >= 3 and v[n-3] == 'E' and v[n-2] == '<' and v[n-1] == 'E' and follow != '*' and follow != '+'){
        v.pop_back();
        v.pop_back();
        return true;
    
    }else if(n >= 4 and v[n-4] == 'v' and v[n-3] == '=' and v[n-2] == 'E' and v[n-1] == ';'){
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.push_back('I');
        return true;
    
    }else if(n >= 5 and v[n-5] == 'i' and v[n-4] == '(' and v[n-3] == 'E' and v[n-2] == ')' and v[n-1] == 'I' and follow != 'e'){
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.push_back('I');
        return true;
    
    }else if(n >= 7 and v[n-7] == 'i' and v[n-6] == '(' and v[n-5] == 'E' and v[n-4] == ')' and v[n-3] == 'I' and v[n-2] == 'e' and v[n-1] == 'I'){
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.push_back('I');
        return true;
    
    }else if(n >= 5 and v[n-5] == 'w' and v[n-4] == '(' and v[n-3] == 'E' and v[n-2] == ')' and v[n-1] == 'I'){
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.push_back('I');
        return true;
    
    }
    else if(n>=2 and v[n-2]== 'L' and v[n-1]=='I'){
        v.pop_back();
        v.pop_back();
        v.push_back('L');
        return true;

    }
    else if(n >= 1 and v[n-1] == 'I' and (n == 1 or (v[n-2] != 'L' and v[n-2] != ')'))){
        v.pop_back();
        v.push_back('L');
        return true;    
    
    } else if(n >= 3 and v[n-3] == '{' and v[n-2] == 'L' and v[n-1] == '}'){
        v.pop_back();
        v.pop_back();
        v.pop_back();
        v.push_back('I');
        return true;

    }else if ( n == 1 and v[n-1] == 'L' and follow == ' ')
    {
        v.pop_back();
        v.push_back('P');
        return true;
    }
   
    

    return false;
}


int main()
{
    string s;
    while (cin >> s) {
        vector<char> v;
        for (int i = 0; i < int(s.size()); i++) {
            v.push_back(s[i]);
            char follow = ' ';
            if (i+1 < int(s.size())) follow = s[i+1];
                
            while (applyOneRule(v, follow)) ;
        }
        string sol;
        for (int i = 0; i < int(v.size()); i++) sol += v[i];
        
        cout << sol << endl;
    }
}