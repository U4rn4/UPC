#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Slot {
 vector<string> listsubjects;
 vector<string> listteachers;
};
typedef vector<vector<Slot> > TableSlots;


int day(string c){
    if (c == "monday")
    {
        return 0;
    }
    else if (c == "tuesday")
    {
        return 1;
    }
    else if (c == "wednesday")
    {
        return 2;
    }
    else if (c == "thursday")
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

int main()
{
    int d,e;
    string a,b,c;
    TableSlots matriz(24, vector<Slot> (5));
    vector<vector<int>> vcount(24, vector<int> (5)) ;
    
    while (cin >> a >> b >> c >> d >> e)
    {
        int dia = day(c);
        
        for (int i = d; i < e; i++)
        {
            matriz[i][dia].listsubjects.push_back(a);
            matriz[i][dia].listteachers.push_back(b);
        }   
    }
    
    cout << "number of subjects per slot:\n" << " h    monday   tuesday wednesday  thursday    friday\n"; 

    int counter = 0;
    for (int i = 0; i < 24; i++)
    {
        if(i<10){
            cout << ' ' << i;
        }
        else{
            cout << i;
        }

        for (int j = 0; j < 5; j++)
        {
            cout << "         " <<matriz[j][i].listsubjects.size();
        }   
        cout << '\n';
    }   
    cout << "number of teachers per slot:\n" << " h    monday   tuesday wednesday  thursday    friday\n"; 

    for (int i = 0; i < 24; i++)
    {
        if(i<10){
            cout << ' ' << i;
        }
        else{
            cout << i;
        }

        for (int j = 0; j < 5; j++)
        {
            sort(matriz[j][i].listteachers.begin(), matriz[i][j].listteachers.end()); 
            for (int k = 0; k < matriz[j][i].listteachers.size() - 1; k++){
                for (int l = 1; l < matriz[j][i].listteachers.size(); l++){
                    if (matriz[j][i].listteachers[k] == matriz[j][i].listteachers[l]) {
                        counter++;
                        ++vcount[j][i];
                    }
                }
            }
            cout << "         " << matriz[j][i].listteachers.size() - vcount[j][i];
        }   
        cout << '\n';
    }   
    
    cout << "number of replacements needed to avoid conflicts:\n" << counter << '\n';

}

