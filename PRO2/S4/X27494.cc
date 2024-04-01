#include <iostream>
#include <list>

using namespace std;

void delet(list<int> &l, int s){
    list<int>::iterator it=l.begin();
    while (it!=l.end())
    {
        if (s==*it)
        {
            l.erase(it);
            return;
        }
        ++it;
    }
    
}

void calc(list<int>& l){
    if (l.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        int max,min;
        float avg;
        list<int>::iterator it = l.begin();
        min=*it;
        max =*it;
        avg = *it;
        it++;
        while (it!=l.end())
        {
            if (max<*it)
            {
                max=*it;
            }
            else if (min>*it) min=*it;
            avg+=*it;
            it++;
        }
        avg = avg/l.size();
        
        cout << min << ' ' << max << ' ' << avg << endl;
        
    }
    
    

}

int main()
{
    int p=1, s=1;
    list<int> l;
    while (cin >> p >> s and (p!=0 or s!=0))
    {
        if(p==-1){
            l.push_back(s);
        }
        else
        {
            delet(l, s);
        }
        calc(l);
    }
    
}