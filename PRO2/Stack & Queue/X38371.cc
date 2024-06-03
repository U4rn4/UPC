// INEFICIENTE 

#include <iostream>
#include <queue>


using namespace std;

void write(queue<int> q){
    int m = q.size();
    int max =  q.front(), min =  q.front();
    float media = q.front();
    q.pop();

    while (not q.empty())
    {
        if (max < q.front()) max = q.front();
        if (min > q.front()) min = q.front();
        media += q.front();
        q.pop();
    }
    
    media = media/m;
    cout << "min " << min << "; max " << max << "; media " << media << endl;
}


int main(){
    queue<int> q;
    int n;
    while (cin >> n and n < 1001 and n > -1002)
    {
        if (n == -1001)
        {
            
            if (not q.empty()) q.pop();

            if (not q.empty())
            {   
                write(q);
            }
            else {
                cout << "0" << endl;
            }
            
        }
        else
        {
            q.push(n);
            write(q);
        }
        
    }
    
}