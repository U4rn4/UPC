#include "evaluatePrefix.hh"
#include <string>


string aux(const BinTree<string> t, const int n, int a){
    if (t.value()=="Concat")
    {
        string s = aux(t.left(),n,a);
        if(s.length()<n or a!=0){
            string s2 = aux(t.right(),n,a);
            return s + s2;
        } 
        return s;
    }
    if (t.value()=="Reverse")
    {
        string s=aux(t.left(),n,a+1);
        string f;
        for (int i = s.length()-1; i >= 0; i--)
        {
            f+=s[i];
        }

        return f;
    }

    return t.value();    
}

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre strings de lletres minúscules i els operadors Concat, Reverse.
//       n>=0
// Post: Retorna el prefix de longitut n de l'avaluació de l'expressió representada per t.
//       En cas que n sigui més gran que la longitut d'aquesta avaluació,
//       llavors retorna només l'avaluació, cap caràcter més.
string evaluatePrefix(BinTree<string> t, int n){
    if (n==0)
    {
        return "";
    }
    return aux(t,n,0).substr(0,n);
}

