#include <iostream>
#include <map>
using namespace std;

int main(){
    cout.setf(ios::fixed);
    cout.precision(4);
    string com;
    map<int,int> m;
    double tot=0;
    double count=0;
    while (cin>>com)
    {
        if (com=="number")
        {
            int num;
            cin>>num;
            tot+=num;
            count++;
            m[num]++;
            map<int,int>::iterator it = m.end();
            it--;
            double jajaj = tot/count;
            cout << "minimum: " << m.begin()->first << ", maximum: " << it->first << ", average: " << jajaj << endl;

        }
        else if (com=="delete")
        {
            if (not m.empty())
            {
                map<int,int>::iterator it = m.begin();
                it->second = it->second - 1;
                tot-=it->first;
                if (it->second==0)
                {
                    m.erase(it);
                }
                count--;
                if (not m.empty())
                {
                    it = m.end();
                    it--;
                    double jajaj = tot/count;
                    cout << "minimum: " << m.begin()->first << ", maximum: " << it->first << ", average: " << jajaj << endl;
                }
                else cout << "no elements" << endl;
            }
            else cout << "no elements" << endl;
        }
        
    }
    
}