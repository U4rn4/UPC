#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> l;
    string str;
    while (cin >> str)
    {
        if (str=="push_front")
        {
            int num;
            cin >> num;
            l.push_front(num);
        }
        else if (str=="push_back")
        {
            int num;
            cin >> num;
            l.push_back(num);
        }
        else if (str=="pop_front")
        {
            if(l.empty()) cout << "error" << endl;
            else l.pop_front();
        }
        else if (str=="pop_back")
        {
            if(l.empty()) cout << "error" << endl;
            else l.pop_back();
        }
        else
        {
            if(l.size()%2 == 0) cout << "error";
            else{
                auto it=l.begin();
                for (int i = 0; i < l.size()/2; i++) ++it;
                cout << *it;
            }
            cout << endl;
        }
        
        
        
    }
    
}