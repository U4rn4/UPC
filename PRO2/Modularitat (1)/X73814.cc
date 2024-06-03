#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a;
    double nota;
    int dni=0;
    int aux=-1;
    cin >> a;
    vector<Estudiant> v(0);
    for (int i = 0; i < a; i++)
    {
        cin >> aux >> nota;
        
        if (dni!=aux)
        {
            Estudiant est(aux);
            if(nota>=0 and nota<=10) est.afegir_nota(nota);
            v.push_back(est);
        }
        else
        {
            if (v.back().te_nota() and nota>=0 and nota<=10 and v.back().consultar_nota()<nota)
            {
                v.back().modificar_nota(nota);
            }
            else if(not v.back().te_nota() and nota>=0 and nota<=10) v.back().afegir_nota(nota);
            
        }
        dni = v.back().consultar_DNI();
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        v[i].escriure();
    }
    

}
