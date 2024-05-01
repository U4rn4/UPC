#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    int c = est.consultar_DNI();
    int i=cerca_dicot(vest,0,nest-1,c);
    b = i<nest and c == vest[i].consultar_DNI() ;
    if (!b)
    {
        i = nest-1;
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
        if(est.te_nota()) {
            double d = est.consultar_nota();
           incrementar_interval(d);
        }
   }
    
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    int i=cerca_dicot(vest,0,nest-1,dni);
    b =  i < nest and vest[i].consultar_DNI() == dni;
    if (b)
        {
        if(vest[i].te_nota()) {
            double a = vest[i].consultar_nota();
            decrementar_interval(a);
        }
        for (int j = i; j < nest-1; j++)
        {
        vest[j] = vest[j+1];
        }
        nest--;
    }
}

void Cjt_estudiants::incrementar_interval(double x) {
       
   int i = x;
    if(i==10) i--;
   ++intervals[i];
}
   
void Cjt_estudiants::decrementar_interval(double x) {
    int i = x;
    if(i==10) i--;
    --intervals[i];
}