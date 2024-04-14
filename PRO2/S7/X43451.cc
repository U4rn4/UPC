#include "Estudiant.hh"
#include <vector>

void arrodonir_vector(vector<Estudiant>& v){
    int n=v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i].te_nota())
        {   
            double num = v[i].consultar_nota();
            num = (((int(10.0 * (num + 0.05))) / 10.0));
            v[i].modificar_nota(num);
        }
        
    }
    
}
   /* Pre: cert */
   /* Post: els estudiants de v amb nota passen a tenir la seva nota arrodonida
 a la decima mes propera */