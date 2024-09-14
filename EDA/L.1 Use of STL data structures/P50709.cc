#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<int> pq;
    int num;
    char com;

    while (cin >> com )
    {
        if (com == 'S')
        {
            cin >> num;
            pq.push(num);
        }
        else if (com == 'A')
        {
            if(not pq.empty()) cout << pq.top() << endl;
            else cout << "error!" << endl;
        }
        else if (com=='R')
        {
            if(not pq.empty()) pq.pop();
            else cout << "error!" << endl;
        }
        else if (com=='I')
        {
            cin >> num;
            if(not pq.empty()){
                int aux = pq.top();
                pq.pop();
                pq.push(aux+num);
            }
            else cout << "error!" << endl;
        }
        else if (com == 'D')
        {
            cin >> num;
            if(not pq.empty()){
                int aux = pq.top();
                pq.pop();
                pq.push(aux-num);
            }
            else cout << "error!" << endl;
        }
    }
    
    return 0;
}