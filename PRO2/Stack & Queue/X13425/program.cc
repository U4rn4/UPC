#include "ParInt.hh"
#include "CuaIOParInt.hh"

int main(){
    queue<ParInt> q;
    llegirCuaParInt(q);
    queue<ParInt> q1;
    queue<ParInt> q2;
    int time1=0, time2=0;

    while (not q.empty())
    {
        if (time1 > time2)
        {
            time2 += q.front().segon();
            q2.push(q.front());
            q.pop();
        }
        else{
            time1 += q.front().segon();
            q1.push(q.front());
            q.pop();
        }
    }
    escriureCuaParInt(q1);
    cout << endl;
    escriureCuaParInt(q2);
    
}