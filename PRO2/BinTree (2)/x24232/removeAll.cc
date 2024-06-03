#include "removeAll.hh"
#include <string>




// Pre:  Els nodes de 't' o bé son strings no buits de lletres minuscules, o bé
//       son de la forma "s.e", on s i e son strings no buits de lletres minúscules.
//       En l'últim cas, el node ha de ser una fulla, i e s'anomena la extensió de la fulla.
// Post: Retorna l'arbre resultant d'esborrar de t tots els nodes amb strings de
//       la forma "s.e" a on 'e' és ig.ual a 'extension'.

BT removeAll(const string &extension, const BT &t){
    if (t.empty())
    {
        return BT();
    }

    string s;
    int i = t.value().length() - extension.length();
    if (i>0 and t.value().substr(i)==extension and t.value()[i-1]=='.')
    {
        return BT();
    }
    else return BT(t.value(),removeAll(extension,t.left()), removeAll(extension,t.right()));
}
