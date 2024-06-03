#include <list>
#include "LlistaIOParInt.hh"
#include "ParInt.hh"




void LlegirLlistaParInt(list<ParInt>& l){

    ParInt p = ParInt();
    list<ParInt>::iterator it;
    it = l.begin();
    p.llegir();
    while ( (p.primer()!= 0 or p.segon()!=0) )
    {
        l.insert(it,p);
        p.llegir();
        
    }
}
// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)

void EscriureLlistaParInt(const list<ParInt>& l){
    int a,siz, times=0, sum=0;
    cin >> a;
    siz = l.size();
    list<ParInt>::const_iterator it; 
    it = l.begin();
    for (int i = 0; i < siz; i++)
    {
        ParInt p = *it;

        if (p.primer() == a)
        {
            times++;
            sum += p.segon();
        }
        it++;
    }
    cout << a << " " << times << " " << sum << endl;
} //(opcional)
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l


/*
MAIN:

#include <iostream>
#include <list>
#include "ParInt.hh"
#include "LlistaIOParInt.hh"

using namespace std;



int main() {
    list<ParInt> aa;
    LlegirLlistaParInt(aa);
    EscriureLlistaParInt(aa); 
    
}
*/