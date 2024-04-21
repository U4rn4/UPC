#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
    int c = est.consultar_DNI();
    int i=cerca_dicot(vest,0,nest-1,c);
    b = c == vest[i].consultar_DNI() ;
    if (!b)
    {
        int i = nest-1;
        bool a = false;
        while (i >= 0 and not a) {  
            if ( c > vest[i].consultar_DNI())  a = true;
            else {
                vest[i+1]=vest[i];
                --i;
            }
        }

        vest[i+1] = est;
        ++nest;
        if(vest[i+1].te_nota()) {
            suma_notes += vest[i+1].consultar_nota();
            ++nest_amb_nota;
        }
    }
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
    int i = cerca_dicot(vest,0,nest-1,dni);
    b = ( vest[i].consultar_DNI() == dni );
    if (b)
    {
        if (vest[i].te_nota())
        {
            suma_notes -= vest[i].consultar_nota();
            --nest_amb_nota;
        }
        vest.erase(vest.begin() + i);
        nest--;
    }
    
}