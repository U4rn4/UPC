#include <iostream>
#include <set>
using namespace std;

int main(){
    string str;
    set<string> s;
    cin>>str;
    set<string>::iterator it = s.begin();
    while ( str!="END")
    {

        s.insert(str);
        if(it==s.end()) it = s.begin();
        if(str<*it and s.size()%2==0){
            it--;
        } 
        else if(str>*it and s.size()%2!=0) it++;
        
        cout << *it << endl;
        cin>>str;
    }
     
}