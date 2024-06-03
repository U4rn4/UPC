/*
    Falta de eficiencia en el programa pero correcto
*/
#include <iostream>
#include "Estudiant.hh"
#include <list>
#include <set>
using namespace std;

int main(){
    int nest,nassig,nselec,aux;
    double aux2,aux3;
    cin >> nest >> nassig >> nselec;
    set<int> st;
    for (int i = 0; i < nselec; i++)
    {
        cin >> aux;
        st.insert(aux);
    }
    list<Estudiant> li;

    for (int i = 0; i < nest; i++)
    {
        aux2=0;
        cin >> aux;
        Estudiant est(aux);
        for (int j = 0; j < nassig; j++)
        {
            cin >> aux3;
            if (st.find(j+1)!=st.end())
            {
                aux2+=aux3;
            }
            
        }
        est.afegir_nota(aux2/st.size());
        
        
        if (not li.empty())
        {
            list<Estudiant>::iterator it = li.begin();
            if (it!=li.end() and it->consultar_nota()==est.consultar_nota())
            {
                while (it!=li.end() and it->consultar_DNI() < est.consultar_DNI())
                {
                    it++;
                }
                li.insert(it,est);
            }
            else
            {
                while (it!=li.end() and it->consultar_nota() > est.consultar_nota())
                {
                    it++;
                }
                li.insert(it,est);
            }
            
            
        }
        else
        {
            li.insert(li.begin(),est);
        }
        
    }
    list<Estudiant>::iterator it = li.begin();
    while (it!=li.end())
    {
        it->escriure();
        it++;
    }
    
    
}