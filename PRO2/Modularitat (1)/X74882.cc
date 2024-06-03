#include <iostream>
#include "Cjt_estudiants.hh"
#include "Estudiant.hh"

using namespace std;

int main(){
    Cjt_estudiants v1;
    Cjt_estudiants v2;

    v1.llegir();

    v2.llegir();

    for (int i = 0; i < v2.mida(); i++)
    {
        Estudiant est2 = v2.consultar_iessim(i+1);
        if (est2.te_nota())
        {
            if (v1.consultar_estudiant(est2.consultar_DNI()).te_nota())
            {
                if (v1.consultar_estudiant(est2.consultar_DNI()).consultar_nota() < est2.consultar_nota())
                {
                    v1.modificar_estudiant(est2);
                }
            }
            else
            {
                v1.modificar_estudiant(est2);
            }
        }
    }
    
    v1.escriure();

}