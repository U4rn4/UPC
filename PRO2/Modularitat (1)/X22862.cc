#include "Cjt_estudiants.hh"
#include <iostream>

using namespace std;

double redondear(double r)
{  
    return int(10.*(r + 0.05)) / 10.0;
} 

int main(){
    Cjt_estudiants v;

    v.llegir();

    int op=0, dni;
    double aux;
    while (cin>>op and op!=-6)
    {
        if (op==-1)
        {
            cin >> dni >> aux;
            if(dni<0) cout << "el DNI es incorrecto" << endl << endl;
            else
            {                
                if (v.existeix_estudiant(dni))
                {
                    cout << "el estudiante " << dni << " ya estaba" << endl << endl;
                }
                else {
                    if (aux>10 or aux<0)
                    {
                        Estudiant est(dni);
                        v.afegir_estudiant(est);
                    }
                    else{
                        Estudiant est(dni);
                        est.afegir_nota(aux);
                        v.afegir_estudiant(est);
                    }
                    
                }
            }
        }
        else if (op==-2)
        {
            cin >> dni;
            if (not v.existeix_estudiant(dni)) cout << "el estudiante " << dni << " no esta" << endl << endl;
            
            else if (v.consultar_estudiant(dni).te_nota())
            {
                cout << "el estudiante " << dni << " tiene nota " << v.consultar_estudiant(dni).consultar_nota() << endl << endl;
            }

            else cout << "el estudiante " << dni << " no tiene nota" << endl << endl;
            
        }
        else if (op==-3)
        {
            cin >> dni >> aux;
            if (v.existeix_estudiant(dni))
            {
                if (aux>10 or aux<0)
                {
                    Estudiant est(dni);
                    v.modificar_estudiant(est);
                }
                else
                {
                    Estudiant est(dni);
                    est.afegir_nota(aux);
                    v.modificar_estudiant(est);
                }
                
            }
            else cout << "el estudiante " << dni << " no esta" << endl << endl;

        }
        else if (op==-4)
        {
            int num=v.mida();
            for (int i = 0; i < num; i++)
            {
                if (v.consultar_iessim(i+1).te_nota())
                {
                    Estudiant est = v.consultar_iessim(i+1);
                    est.modificar_nota(redondear(est.consultar_nota()));
                    v.modificar_estudiant(est);
                }
                
            }
            
        }
        else if (op==-5)
        {
            v.escriure();
            cout << endl;
        }
        
    }
    
}