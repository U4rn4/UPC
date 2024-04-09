#include "numIncreasing.hh"

// Pre:
// Post: Retorna el nombre de nodes de t que no son l'arrel de t i que guarden un valor
//       estrÃ­ctament major que el valor guardat al seu node pare.
int numIncreasing(BinTree<int> t){
    if (t.empty())
    {
        return 0;
    }
    else if ((not t.left().empty()) and (t.left().value()>t.value()) and (not t.right().empty()) and t.right().value()>t.value())
    {
        return 2+ numIncreasing(t.right()) + numIncreasing(t.left());
    }
    
    else if ((not t.left().empty()) and t.left().value()>t.value())
    {
        return 1 + numIncreasing(t.right()) + numIncreasing(t.left());
    }
    else if ((not t.right().empty()) and t.right().value()>t.value())
    {
        return 1 + numIncreasing(t.right()) + numIncreasing(t.left());
    }
    else return numIncreasing(t.right()) + numIncreasing(t.left());
    
}
