#include <iostream>
#include "Estudiant.hh"
#include <set>
#include <vector>
using namespace std;

int main(){
    int nest,nassig,nselec, num;
    cin >> nest >> nassig >> nselec;
    set<int> s;
    for (int i = 0; i < nselec; i++)
    {
        cin>>num;
        s.insert(num-1);
    }
    int dni;
    double nota, aux;
    vector<Estudiant> v(nest);
    for (int i = 0; i < nest; i++)
    {
        aux=0;
        cin >> dni;
        for (int j = 0; j < nassig; j++)
        {
            cin >> nota;
            if (s.find(j)!=s.end())
            {
                aux+= nota;
            }
            
        }
        aux=aux/nselec;
        Estudiant est(dni);
        est.afegir_nota(aux);
        v[i]=est;
    }

    for (int i = 0; i < nest; i++)
    {
        v[i].escriure();
    }
}