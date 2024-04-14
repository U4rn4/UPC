/*
El ejercicio da 4/6, fallan el de eficiencia y el primer privado(por la cara).
Si alguien tiene la solucion 6/6 hacer pull request o enviarmela por el discord u4rn4 o por wsp(en el grupo soy el arnau al que no se le ocurre nada)
*/


#include "Estudiant.hh"
#include <vector>

void simplificar_vector(vector<Estudiant>& v, int& pos){
    int last=-2;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i].consultar_DNI()!=last){
            last=v[i].consultar_DNI();
            if (not v[i].te_nota())
            {
                v.erase(v.begin()+i);
                i--;
                last=-2;
            }
        }
        else
        {
            if(not v[i].te_nota()){
                v.erase(v.begin()+i);
            }
            else{
                if (v[i].consultar_nota()>v[i-1].consultar_nota())
                {
                    v.erase(v.begin()+i-1);
                }
                else v.erase(v.begin()+i);
                
            }
            --i;
        }
        
    }
    if(v.size()!=0) pos=v.size()-1;
    else pos=0;
}

 /* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
 /* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
    nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
    ordre que a V */
