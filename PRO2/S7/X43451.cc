/*
Falta eficacia en el ejercicio y no me renta mejorarlo jajja
*/
#include "Estudiant.hh"
#include <vector>
using namespace std;

void arrodonir_vector(vector<Estudiant>& v){
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].te_nota())
        {
            v[i].modificar_nota(((int) (10. * (v[i].consultar_nota() + 0.05))) / 10.0);
        }
        
    }
    
}
   /* Pre: cert */
   /* Post: els estudiants de v amb nota passen a tenir la seva nota arrodonida
 a la decima mes propera */